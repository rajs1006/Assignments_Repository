# -*- coding: utf-8 -*-
"""
Created on Tue Oct  2 23:05:26 2018

@author: princ
"""

import numpy

A = numpy.identity(2)
B = numpy.ones((2,1))

print(A)
print(B)

print(((B.T.dot(A.T)).dot(A.T.dot(B))).shape)