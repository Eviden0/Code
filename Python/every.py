import requests
url ='https://acm.xtu.edu.cn/exam/index.php/exam/problems/exam_id/232'
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'
    ,'Cookie': 'PHPSESSID=d2kjdfdcb9gvflartllejhe7a2'
}
def download(secondurl,headers):
    from lxml import etree
    tree=etree.HTML(requests.get(url,headers=headers).text) 
    td_elements = tree.xpath('//td[@colspan="2" and @align="left"]//a')
    # 打印提取到的<a>标签的文本内容和href属性
    for a in td_elements:
        text = a.text.strip()
        href = a.get('href')
        print(f"text: {text}, href: {href}")