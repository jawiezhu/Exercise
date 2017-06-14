# -*- coding: utf-8 -*-
"""
Created on Sun May 29 16:22:56 2016

@author: JawieZhu
"""

from bs4 import BeautifulSoup
import urllib2

def getHtmlDoc(url): 
    headers={'User-Agent':'Mozilla/5.0(Windows;U;Windows NT 6.1;en-US;rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'}
    req=urllib2.Request(url,headers=headers)
    page=urllib2.urlopen(req,timeout=600)
    contents=page.read()
    print contents

if __name__=='__main__':
    url="http://www.stat-nba.com/playerList.php?il=A&lil=0"   
    getHtmlDoc(url)