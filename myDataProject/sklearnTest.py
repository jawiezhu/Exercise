# -*- coding: utf-8 -*-
"""
Created on Thu Aug 25 15:53:59 2016

@author: JawieZhu
"""

from sklearn import datasets
from sklearn.cross_validation import cross_val_predict
from sklearn import linear_model
import matplotlib.pylab as plt

lr=linear_model.LinearRegression()
boston=datasets.load_boston()

y=boston.target

predicted=cross_val_predict(lr,boston.data,y,cv=10)

fig,ax=plt.subplots()
ax.scatter(y,predicted)

ax.plot([y.min(),y.max()],[y.min(),y.max()],'k--',lw=4)

ax.set_xlabel('measured')
ax.set_ylabel('predicted')

plt.show()
