# -*- coding: utf-8 -*-
"""
Created on Wed Jun  8 09:13:37 2016

@author: JawieZhu
"""

import pandas as pd
import matplotlib.pyplot as plt
import pylab as pl

def clk(path):
    clk=pd.read_csv(path)
    
    clk=clk.loc[:,['gender','age']]
    
    clk_man=clk[clk.gender == 1]
    clk_women=clk[clk.gender == 2]

    clk_man=clk_man.reset_index(drop=True)
    clk_women=clk_women.reset_index(drop=True)
    clk_man.index+=1
    clk_women.index+=1

    fig=plt.figure()
    #fig.suptitle('clk')
    ax=fig.add_subplot(111)
    ax.set_title('man')
    ax.set_xlabel('id')
    ax.set_ylabel('age')
    ax.plot(clk_man.index,clk_man['age'],color='r',marker='o')
    plt.savefig('/Users/JawieZhu/Desktop/man.jpg')
    plt.show()


    fig=plt.figure()
    ax=fig.add_subplot(111)
    ax.set_title('woman')
    ax.set_xlabel('id')
    ax.set_ylabel('age')
    ax.plot(clk_women.index,clk_women['age'],color='g',marker='o')
    plt.savefig('/Users/JawieZhu/Desktop/women.jpg')    
    plt.show()




if __name__=="__main__":
        clk("/Users/JawieZhu/Desktop/push.csv")