#!/usr/bin/python
#-*-coding:utf-8 -*-
#Author   : Zodiac
#Version  : 1.0
#Filename : rotate_with_reverse.py
def Reverse(arr, left, right):
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left, right = left+1, right-1

def Rotate(arr, d, n):
    Reverse(arr, 0, d-1)
    Reverse(arr, d, n-1)
    Reverse(arr, 0, n-1)


for i in range(1, 8):
    a = range(1, 8)
    print a
    Rotate(a, i, len(a))
    print a
    print "-"*20
