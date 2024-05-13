<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept, Authorization");
header('Access-Control-Allow-Methods: GET, POST, PUT,DELETE,OPTIONS,PATCH');

class Server{

    const DS = '/';

    protected $config = [];

    protected $runtime_path;

    /**
     * 初始化
     * @param array $config
     */
    public function __construct(array $config = [])
    {
        // 默认配置
        $default = [
            'token' => '',
            'chunks_path' => '/chunks/',
            'upload_path' => '/upload/',
            'min_file_size' => 2 * 1024 * 1024
        ];
        // 获取配置信息
        $this->config = array_merge($default,$config);

        // 运行目录
        $this->runtime_path = $this->getFitSeparator(__DIR__);

    }


    /**
     * 构建器
     * @param $config
     */
    public static function create($config){
        try {
            (new self($config))->start();
        }catch (Throwable $e){
            if($e->getCode() == 077)
                exit($e->getMessage());
            exit(json_encode(['code' => 0,'msg' => $e->getMessage()]));
        }
    }

    /**
     * 运行远程服务器
     * @throws Exception
     */
    public function start(){
        // 签名
        $sign = $_GET['sign'] ?? '';

        if(empty($sign)){
            $this->returnJson(0,'数据签名不存在');
        }

        if(!$this->sign_verify($_GET,$sign)){
            $this->returnJson(0,'数据签名验证失败');
        }
                // 上传文件
                $info = $this->upload_file($_GET['uid']);
                // 额外参数
                $info['uid'] = $_GET['uid'];
                // 回调通知
                $res = $this->upload_notify($_GET['notify'],$info);
                $this->returnJson(1,'上传文件成功');
    }


    /**
     * 上传文件到服务器
     * @param $uid
     * @return array
     * @throws Exception
     */
    protected function upload_file($uid): array
    {
        // 获取上传文件
        $file = $_FILES["file"];

        if(!$file){
            $this->returnJson(0,'请选择需要上传的文件');
        }


        // 文件后缀
        $file_ext = strtolower(pathinfo($file['name'],PATHINFO_EXTENSION));

        // 获取保存目录
        $save_dir = $this->getUserUploadPath($uid);

        // 获取保存文件夹
        $file_name = 'file_'.$this->getRandomName(16);

        // 最终保存路径
        $save_file = $this->runtime_path . $save_dir . $file_name .'.'. $file_ext;

        // 保存文件
        move_uploaded_file($file["tmp_name"], $save_file);


        if(!is_file($save_file)){
            $this->returnJson(0,'文件上传失败：Error Move Files');
        }

        $size = filesize($save_file);

        $finfo = finfo_open(FILEINFO_MIME_TYPE);
        $mime_type = finfo_file($finfo,$save_file);

        // 文件信息
        return [
            'name' => $file['name'],
            'ext' => $file_ext,
            'path' => $save_dir . $file_name .'.'. $file_ext,
            'size' => $size,
            'mime' => $mime_type
        ];

    }


    /**
     * 获取用户上传目录
     * @param $uid
     * @return array|string|string[]
     */
    protected function getUserUploadPath($uid){
        $root = $this->runtime_path;
        $path = $this->getFitSeparator($this->config['upload_path'] . date('Ymd') . self::DS . $uid . self::DS);

        $save_path = $this->getFitSeparator($root.$path);

        is_dir($save_path) || mkdir($save_path,0775,true);

        return $path;
    }

    /**
     * 获取随机文件名
     * @param int $length
     * @return string
     */
    protected function getRandomName(int $length = 16): string
    {
        $charTable = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
        $result = "";
        for ( $i = 0; $i < $length; $i++ ){
            $result .= $charTable[ mt_rand(0, strlen($charTable) - 1) ];
        }
        return $result;
    }

    /**
     * 获取一致化目录分隔符
     * @param $dir
     * @param string $ds
     * @return array|string|string[]
     */
    protected function getFitSeparator($dir, string $ds = ''){
        $ds = empty($ds) ? self::DS : $ds;
        return str_replace(['\\','/','\\\\','//'],$ds,$dir);
    }


    /**
     * 返回json内容
     * @param $code
     * @param $msg
     * @param $data
     * @return void
     * @throws Exception
     */
    protected function returnJson($code, $msg, $data = null){
        $result = [
            'code' => $code,
            'msg' => $msg
        ];

        if(is_array($data)){
            $result = array_merge($result,$data);
        }else if (is_string($data)){
            $result['data'] = $data;
        }

        $json = json_encode($result);

        throw new Exception($json,077);
    }

    /**
     * 参数签名
     * @param $params
     * @return string
     */
    protected function sign_params($params): string
    {
        // 过滤参数
        $params = array_filter($params,function($key) use ($params){
            if(empty($params[$key]) || $key == 'sign'){
                return false;
            }
            return true;
        },ARRAY_FILTER_USE_KEY);

        // ascii排序
        ksort($params);
        reset($params);

        // 签名
        return md5(urldecode(http_build_query($params)) . $this->config['token']);
    }

    /**
     * 签名验证
     * @param $params
     * @param $sign
     * @return bool
     */
    protected function sign_verify($params,$sign): bool
    {
        return $this->sign_params($params) == $sign;
    }

    /**
     * 回调通知上传
     * @param $url
     * @param $param
     * @return bool|string
     */
    protected function upload_notify($url,$param)
    {
        // 生成签名
        $sign = $this->sign_params($param);
        $param['sign'] = $sign;

        // 请求地址
        $request_url = $url.'?'.urldecode(http_build_query($param));

        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $request_url);
        curl_setopt($ch, CURLOPT_HEADER, 0);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
        curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE);

        $result = curl_exec($ch);
        curl_close($ch);
        return $result;
    }

}

Server::create(['token' => 'QiuQIuYyds', 'upload_path' => '/upload/']);