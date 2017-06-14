# -*- coding: utf-8 -*-
"""
Created on Tue May 31 09:01:29 2016

@author: JawieZhu
"""

import pandas as pd
import numpy as np
import datetime
import time


def getRatingData(path):
    result=[]
    for line in open(path,"r"):
        result.append(line.strip("\n\r").split("\t"))
    rating=pd.DataFrame(result,index=range(1,len(result)+1),columns=[\
    "userid","itemid",\
    "rating","timestamp"])
    return rating

def getUserData(path):
    result=[]
    for line in open(path,"r"):
        result.append(line.strip("\n\r").split("|"))
    user=pd.DataFrame(result,index=range(1,len(result)+1),columns=[\
    "userid","age",\
    "gender","occupation",\
    "zipcode"])
    return user

def getItemData(path):
    result=[]
    for line in open(path,"r"):
        result.append(line.strip("\n\r").split("|"))
    item=pd.DataFrame(result,index=range(1,len(result)+1),columns=["movieid",\
    "movietitle","releasedate","videoreleasedate",\
    "IMDbURL","unknown","Action",\
    "Adventure","Animation",\
    "Children's","Comedy","Crime","Documentary","Drama",\
    "Fantasy","Film-Noir",\
    "Horror","Musical",\
    "Mystery","Romance","Sci-Fi",\
    "Thriller","War","Western"
    ])
    return item
    
def getDataFrame():
    ratingData=getRatingData("/Users/JawieZhu/Desktop/ml-100k/u.data")
    userData=getUserData("/Users/JawieZhu/Desktop/ml-100k/u.user")
    itemData=getItemData("/Users/JawieZhu/Desktop/ml-100k/u.item")
    return ratingData,userData,itemData
    
def timestampToTime(mytime):
    ltime=time.localtime(float(mytime))
    timeStr=time.strftime("%Y-%m-%d %H:%M:%S",ltime)
    return timeStr
    
def ratingDataTimeStampToTime(df):
    list1=[]
    for i in range(1,len(df)+1):
        x=timestampToTime(df['timestamp'][i])
        list1.append(x)
    df['time']=pd.Series(list1,index=df.index)
    df=df.drop(['timestamp'],axis=1)
    return df
    
def getZipCode(df):
    ziplist=[]
    for i in range(1,len(df)+1):
        x=df['zipcode'][i]
        ziplist.append(x)
    zipSet=set(ziplist)
    return zipSet
    #print len(ziplist)
    #print zipSet
    
def getOccupation(df):
    occupationlist=[]
    for i in range(1,len(df)+1):
        x=df['occupation'][i]
        occupationlist.append(x)
    occupationSet=set(occupationlist)
    return occupationSet
    
def getRatingMean(df):
    sum=0
    for i in range(1,len(df)+1):
        x=df['rating'][i]
        sum=sum+int(x)
    print "rating mean is : %f" %(float(sum)/len(df))

        
    
if __name__=="__main__":
    ratingData,userData,itemData=getDataFrame()

    ratingData=ratingDataTimeStampToTime(ratingData)
    zipCodeSet=getZipCode(userData)
    occupationSet=getOccupation(userData)
    ratingMean=getRatingMean(ratingData)
    #print ratingData['rating']
   
    
    
    
    
    