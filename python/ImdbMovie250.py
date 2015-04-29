import urllib2
from bs4 import BeautifulSoup
mylist=[]

def crawl(url):
	headers={'User-Agent':'Mozilla/5.0(Windows;U;Windows NT 6.1;en-US;rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'}
	req=urllib2.Request(url,headers=headers)
	page=urllib2.urlopen(req,timeout=200)
	contents=page.read()
	
	soup=BeautifulSoup(contents)
	#print soup.prettify()
	#p=soup.findAll('td',class_='titleColumn')
	#print p
	for tag in soup.find_all('tr',class_={'odd','even'}):
		#try:
			m_order=tag.find('td',class_='titleColumn').span.get_text()
			m_name=tag.find('td',class_='titleColumn').a.get_text()
			m_rating_score=float(tag.find('td',class_='ratingColumn imdbRating').strong.get_text())
			#m_rating_num=tag.find('div',class_='star').span.next_sibling.next_sibling.get_text()
			#m_comments=tag.find('span',class_='inq').get_text()
		#except AttributeError:
			#print("%s %s" % (m_order,m_name))
			#mylist.append((m_order,m_name))
		#else:
			print("%s %s %s" % (m_order,m_name,m_rating_score))
			mylist.append((m_order,m_name,m_rating_score))


crawl('http://www.imdb.com/chart/top?ref_=nv_ch_250_4')

#只爬取到11个。第11行 未能完整放入。
