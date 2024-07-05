import requests
from lxml import html
url ='https://acm.xtu.edu.cn/exam/'
name='202205501919'
passwd=name+'.'
# postdata=f'crsf_token={}&username={name}&capture=login&password={passwd}&Submit=Login'
headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36'
}
def login(name,passwd):
    url = 'https://acm.xtu.edu.cn/exam/'
    res=requests.get(url, headers=headers)
    parsed_html = html.fromstring(res.text)
    csrf_token = parsed_html.xpath('//input[@name="crsf_token"]/@value')[0]
    print(csrf_token)
    postdata=f'crsf_token={csrf_token}&username={name}&capture=login&password={passwd}&Submit=Login'
    res=requests.post(url,data=postdata,headers=headers)
    print(postdata)
    if 'No such username or invaild password ' in res.text or 'The page is outdated' in res.text:
        print('登录失败')
    else:
        if 'Welcome: 202205501919' in res.text:
            print('登录成功')
        else:
            print('登录失败')
        # print('登录成功')
        # print(type(res.cookies))
        phpsessid = res.cookies.get('PHPSESSID')

        print(phpsessid)
        url='https://acm.xtu.edu.cn/exam/index.php/user/edit'
        cookies={
            'PHPSESSID':f'{phpsessid}'
        }
        res=requests.get(url,headers=headers,cookies=cookies)
        if '黄烊' in res.text:
            print('登录成功')
        else:
            print('登录失败')

login(name,passwd)
# print(res.text)