#!/usr/bin/env python

import matplotlib.pyplot as plt
import sys

stocks = ""
foundFuture = False
for line in sys.stdin:
    stocks += (line)

list = stocks.split(' ')

list1 = []
list2 = []
ok = False
for line in list:
    if (line == "CUT" ):
        ok = True
    elif ok:
        list2.append(line)
    else:
        list1.append(line)
    
ticker = list1[0]
list1.remove(ticker)
list1 = [float(k) for k in list1]

list2.remove('')
list2 = [float(k) for k in list2]

plt.plot(list1)
plt.plot(list2)
plt.ylabel(ticker + "(Blue) Stock Price VS SPY (Green)")
plt.xlabel("Past 250 Trading Days")
plt.show()