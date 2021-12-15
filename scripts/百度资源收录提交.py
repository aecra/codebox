# coding:utf-8
import requests
import os
from urllib.parse import quote

headers = {
    'User-Agent': 'curl/7.12.1',
    'Host': 'data.zz.baidu.com',
    'Content-Type': 'text/plain'
}

url = "http://data.zz.baidu.com/urls?site=https://www.aecra.cn&token=<添加自己的token>"
session = requests.session()

folder = 'F:/Users/aecra/Desktop/hexo/public/'
site = 'https://www.aecra.cn/'

urls = []


def read_html(rootDir):
    for lists in os.listdir(rootDir):
        path = os.path.join(rootDir, lists)
        if os.path.isdir(path):
            read_html(path)
        elif os.path.isfile(path):
            if lists == 'index.html':
                urls.append(rootDir.replace("\\", '/').replace(folder, site))


read_html(folder)

data = ''
for item in urls:
    data = data + quote(item).replace('https%3A','https:') + '\n'


requ = session.post(url, data=data, headers=headers)
res = requ.text
print(res)
