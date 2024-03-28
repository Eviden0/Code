import requests 
url = "baidu.com"

re=requests.get(url=url)
print(re.status_code)