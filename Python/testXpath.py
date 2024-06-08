from lxml import etree
import requests
url ='http://acm.xtu.edu.cn/exam/index.php/exam/past?&p='
# with open('exam.txt','r') as f:
#     html_content=f.read()
ua={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36'}
html_content = requests.get(url=url,headers=ua).text
tree = etree.HTML(html_content)
# print(html_content)
def Get_pageNum(tree):
    
    Page=tree.xpath('//tr[@class="page_link"]/td/div')[0]
    # maxPageNum=Page.xpath('./text()')[0][:-2].strip()
    return int(Page.xpath('./text()')[0][-6:-4].strip())
    # print(Page.xpath('./text()')[0][-6:-4].strip())#共400 条记录/20页
def Page_date(url,index):
    url=url+index
    print(f"当前是第{index}页的记录"+url)
    ascii=""" ___    ___  _________       
|\  \  /  /||\___   ___\ |\  \|\  \    
\ \  \/  / /\|___ \  \_| \ \  \\\  \   
 \ \    / /      \ \  \   \ \  \\\  \  
  /     \/        \ \  \   \ \  \\\  \ 
 /  /\   \         \ \__\   \ \_______\
/__/ /\ __\         \|__|    \|_______|
|__|/ \|__| """
    print(ascii)
    # print(url)
    html_content = requests.get(url=url, headers=ua).text
    tree = etree.HTML(html_content)
    tr_list = tree.xpath('//tr')
    links = []
    for tr in tr_list:
        a_elements = tr.xpath('./td/a')
        for a in a_elements:
            text = a.text.strip()
            href = a.get('href')
            if '学期' in text:
                # print(f"title: {text}, href: {href}")
                links.append({'title': text, 'href': href})
    return links

def download(secondurl,headers):
    from lxml import etree
    tree=etree.HTML(requests.get(url,headers=headers).text) 
    td_elements = tree.xpath('//td[@colspan="2" and @align="left"]//a')
    # 打印提取到的<a>标签的文本内容和href属性
    for a in td_elements:
        text = a.text.strip()
        href = a.get('href')
        print(f"text: {text}, href: {href}")    
def Scan_page(links):
    url='http://acm.xtu.edu.cn'
    for i in links:
        print(i['title'],url+i['href'])   


Get_pageNum(tree)
for i in range(1,Get_pageNum(tree)+1):
    Scan_page(Page_date(url,str(i)))
# print(('12/3').find('/'))