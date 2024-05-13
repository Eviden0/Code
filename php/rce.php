<?php
if($_GET['moran'] === 'flag'){
    highlight_file(__FILE__);
    if(isset($_POST['task'])&&isset($_POST['flag'])){
        $str1 = $_POST['task'];
        $str2 = $_POST['flag'];
        if(preg_match('/system|eval|assert|call|create|preg|sort|{|}|filter|exec|passthru|proc|open|echo|`| |\.|include|require|flag/i',$str1) || strlen($str2) != 19 || preg_match('/please_give_me_flag/',$str2)){
            die('hacker!');
        }else{
            $a=preg_replace("/please_give_me_flag/ei",$_POST['task'],$_POST['flag']);
            //大小写绕过,然后怎么命令执行呢?
            // echo $str1.'\n'.$str2;
        }
    }
}else{
    echo "moran want a flag.</br>(?moran=flag)";
} 