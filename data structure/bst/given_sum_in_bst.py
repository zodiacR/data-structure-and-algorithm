#!/usr/bin/python
#-*-coding:utf-8 -*-
#Author   : Zodiac
#Version  : 1.0
#Filename : given_sum_in_bst.py
class Node(object):
    def __init__(self, val):
        self.val = val;
        self.left = self.right = None

def FindGivenSum(root, sum):
    left_stack = []
    right_stack = []
    done1 = False
    done2 = False
    tmp1 = tmp2 = root

    while True:
        while not done1:
            while tmp1:
                left_stack.append(tmp1)
                tmp1 = tmp1.left

            if (left_stack):
                top = left_stack[-1]
                val1 = top.val
                left_stack.pop()
                tmp1 = top.right
                done1 = True
                
            else: done1 = True

        while not done2:
            while tmp2:
                right_stack.append(tmp2)
                tmp2 = tmp2.right

            if (right_stack):
                top = right_stack[-1]
                val2 = top.val
                right_stack.pop()
                tmp2 = top.left
                done2 = True
                
            else: done2 = True

        if val1 != val2 and val1 + val2 == sum:
            print "%d + %d = %d" % (val1, val2, sum)
            return True
        
        elif val1 + val2 < sum:
            done1 = False
        elif val1 + val2 > sum:
            done2 = False

        if val1 >= val2: return False

if __name__ == "__main__":
    root = Node(15)
    root.left = Node(10)
    root.right = Node(20)
    root.left.left = Node(8)
    root.left.right = Node(12)
    root.right.left = Node(16)
    root.right.right = Node(25)

    if not FindGivenSum(root, 19):
        print "No such values satisfy"
