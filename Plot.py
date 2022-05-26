# -*- coding: utf-8 -*-
"""
Created on Wed Apr 27 01:33:26 2022

@author: 88697
"""

import numpy as np
import matplotlib.pyplot as plt

f=open("C:/Users/88697/Desktop/inputdata.txt","r")
x=[]
y=[]
l=[]
def plotvoronoid(l):
    temp=l.split(" ")
    x=[]
    y=[]
    x.append(float(temp[1]))
    x.append(float(temp[4]))
    y.append(float(temp[2]))
    y.append(float(temp[5]))
    vectorx=x[1]-x[0]
    vectory=y[1]-y[0]
    if temp[3]=="0":
        
          if vectorx<100 and vectory<100:
              #m=100/vectorx
              vectorx*=100
              vectory*=100
              y[1]=y[0]+vectory
              x[1]=x[0]+vectorx
        
            
    plt.plot(x,y)
    
    
    
for line in f.readlines(): 
    b=line.strip("\n")
    a=b.split(" ")
    if (a[0]!="0"and a[0]!="1"):
        x.append(float(a[0]))
        y.append(float(a[1]))
    else:
        l.append(b)
for i in l:
    plotvoronoid(i)
    
plt.scatter(x,y)    
f.close()
plt.xlim(-250,250)
plt.ylim(-250,250)