import requests
url="http://202.197.224.59/"
# <td colspan="2" align="left">&nbsp;&nbsp;&nbsp;&nbsp;1457&nbsp;&nbsp;<a href="/exam/index.php/problem/exam_read/id/1457/exam_id/462">图像</a></td>
# http://202.197.224.59/exam/index.php/exam/problems/exam_id/465  练习3
# http://202.197.224.59/exam/index.php/exam/problems/exam_id/462 练习2
url_findurl_list={
    '练习2':'http://202.197.224.59/exam/index.php/exam/problems/exam_id/462',
    '练习3':'http://202.197.224.59/exam/index.php/exam/problems/exam_id/465'
}
url_findURL = 'http://202.197.224.59/exam/index.php/exam/problems/exam_id/462'
cookie={
    'PHPSESSID':'fr0lifd6mkd4i0r75vor3p2si5'
}
def get_url(name,url,cookie):
    print(f'开始爬取 {name}! ')
    ua='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36'
    re1=requests.get(url,headers={'User-Agent':ua},cookies=cookie)
    # return re.text
    import re
    pattern=re.compile('<td colspan="2" align="left">&nbsp;&nbsp;&nbsp;&nbsp;.*&nbsp;&nbsp;<a href="(.*?)">(.*?)</a></td>')
    res=re.findall(pattern,re1.text)
    return res


js='''
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML"></script>
<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js"></script>
'''
res=get_url(url_findURL,cookie)
# 分练习1 练习2 ...这种爬取
def download(res):
    
    for i in res:
        import requests
        page_url = url+i[0]
        ua='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36'
        content=requests.get(page_url,headers={'User-Agent':ua}).text
        name=i[0].split("/")[-3]+'_'+i[1]
        # w是覆盖写入，a是追加写入
        with open(f'/usr/Code/Xtuoj/爬虫/练习2/{name}.html',"w") as f:
            f.write(js+'\n'+content)
        print(f'{name}爬取成功~')