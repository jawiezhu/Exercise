# -*- coding: utf-8 -*-
"""
Created on Sun Apr 30 17:36:25 2017

@author: JawieZhu
"""

import urllib2
from bs4 import BeautifulSoup


def test(url):
	headers={'User-Agent':'Mozilla/5.0(Windows;U;Windows NT 6.1;en-US;rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'}
	req=urllib2.Request(url,headers=headers)
	page=urllib2.urlopen(req,timeout=60)

	print page.read()


if __name__=='__main__':
	#url='https://bbs.hupu.com/vote'

	#test(url)

      a=[i/10.0 for i in range(1,101)]
      b=[i/10.0 for i in range(1,101)]
      c=[i/10.0 for i in range(1,101)]
      d=[i/10.0 for i in range(1,101)]
      
      for x in a:
          for y in b:
              for z in c:
                 for p in d:
                     if(x+y==8 and y+p==8 and z-p==6 and x+z==13):
                         print x,y,z,p
                         
                
            