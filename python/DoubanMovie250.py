import urllib2
from bs4 import BeautifulSoup
mylist=[]

def crawl(url):
	headers={'User-Agent':'Mozilla/5.0(Windows;U;Windows NT 6.1;en-US;rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'}
	req=urllib2.Request(url,headers=headers)
	page=urllib2.urlopen(req,timeout=60)
	contents=page.read()
	soup=BeautifulSoup(contents)
	for tag in soup.find_all('div',class_='item'):
		try:
			m_order=int(tag.find('em',class_='').get_text())
			m_name=tag.span.get_text()
			m_rating_score=float(tag.find('div',class_='star').em.get_text())
			m_rating_num=tag.find('div',class_='star').span.next_sibling.next_sibling.get_text()
			m_comments=tag.find('span',class_='inq').get_text()
		except AttributeError:
			print("%s %s %s %s %s" % (m_order,m_name,m_rating_score,m_rating_num,"NO COMMENTS"))
			mylist.append((m_order,m_name,m_rating_score,m_rating_num,"NO COMMENTS"))
		else:
			print("%s %s %s %s %s" % (m_order,m_name,m_rating_score,m_rating_num,m_comments))
			mylist.append((m_order,m_name,m_rating_score,m_rating_num,m_comments))

pagenumber=[]
for i in range(10):
	page_number=25*i
	pagenumber.append(page_number)
pagelist=list(map(str,pagenumber))

BASE_URL='http://movie.douban.com/top250?start='
LAST_URL='&filter=&type='
for url in [BASE_URL + MID_URL + LAST_URL for MID_URL in pagelist]:
	crawl(url)