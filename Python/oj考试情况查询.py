import requests

# class OJ:
#     def __init__(self, username, password):
#         self.username = username
#         self.password = password
#         self.session = requests.Session()
def Get_exam_status():
    url='http://172.22.112.246/exam/index.php/exam/past'
    headers={
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
        'Referer': 'http://172.22.112.246/exam/index.php/exam/past',
    }
    res=requests.get(url,headers=headers)
    print(res.text)



    
uid=input('请输入学号：')
exam_id=input('请输入考试号：')
timuindex=input('请输入题目序号(初始以第一道题默认序号)：')# +5
url=f'http://172.22.112.246/exam/index.php/solution/onlinestatus/exam_id/{exam_id}/problem_id/{timuindex}'
headers={
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
    'Referer': f'http://172.22.112.246/exam/index.php/solution/onlinestatus/exam_id/{exam_id}/problem_id/{timuindex}',
}
res=requests.post(url,headers=headers)
print(res.text)