import frontmatter
import pymysql
import os

# config
post_folder = 'F:/Users/aecra/Desktop/hexo/source/_posts/'
database = {
    'host': '',
    'user': '',
    'passwd': '',
    'db': ''
}

# 读取所有的文章的内容
print("读取文章内容......")
posts = os.listdir(post_folder)

article_data = []

for post in posts:
    f = open(post_folder + post, encoding='utf-8-sig')
    item = frontmatter.loads(f.read())
    article = {
        'title': item['title'],
        'date': item['date'],
        'tags': item['tags'],
        'cover': item['cover'],
        'content': item.content
    }
    article_data.append(article)
article_data = sorted(article_data, key=lambda article: article['date'])
print("已读取文章内容")

# 连接数据库，进行数据库操作
print('连接数据库......')
conn = pymysql.connect(
    host=database['host'], user=database['user'], passwd=database['passwd'], db=database['db'], charset='utf8')
cursor = conn.cursor()
print('已连接数据库')

# 删除原有文章数据
print('清空数据库......')
cursor.execute('truncate table tagmaptb')
cursor.execute('truncate table tagstb')
cursor.execute('truncate table articletb')
print('已清空数据库')

# 向数据库中添加数据
print('正在向数据库中添加文章......')
i = 0
for article in article_data:
    i = i + 1
    # 添加文章
    sql = ('INSERT INTO articletb '
           '(title,img_url,content,publish_time,update_time,userid) '
           'VALUES(%s,%s,%s,%s,%s,1)')
    cursor.execute(sql, [article['title'], article['cover'],
                         article['content'], article['date'], article['date']])
    # 获取文章id
    article_id = cursor.lastrowid
    # 建立文章和标签的链接
    for tag in article['tags']:
        # 标签不存在就插入标签
        res = cursor.execute('select * from tagstb where tagname=%s', [tag])
        if res == 0:
            cursor.execute('insert into tagstb(tagname) values(%s)', [tag])
        # 获取标签id
        cursor.execute('select * from tagstb where tagname=%s', [tag])
        tag_id = cursor.fetchone()[0]
        # 向映射表中插入数据
        cursor.execute('insert into tagmaptb(tagid,articleid) values(%s,%s)', [
                       tag_id, article_id])
    print('(', i, '/', len(article_data), ') 已添加：', article['title'])
print('添加完成')

# 关闭数据库
print('关闭数据库......')
cursor.close()
conn.close()
print('已关闭数据库')
