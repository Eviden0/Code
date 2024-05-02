import re

url="http://202.197.224.59/"

with open("url.txt","r") as f:
    txt=f.read()

pattern=re.compile('<a href="(.*?)">(.*?)</a>',re.S)
res=re.findall(pattern,txt)
js='''
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML"></script>
<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js"></script>
'''
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
        