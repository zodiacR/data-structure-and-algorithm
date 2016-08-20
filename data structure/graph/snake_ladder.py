#!/usr/bin/python
#-*-coding:utf-8 -*-
#Author   : Zodiac
#Version  : 1.0
#Filename : snake_ladder.py
class Cell(object):
    def __init__(self, v, dist):
        self.v = v
        self.dist = dist

def SnakeLadder(move):
    N = len(move)
    visited = [False for _ in range(N)]
    q = list()
    c = Cell(0, 0)
    visited[0] = True
    q.append(c)

    while q:
        c = q.pop(0)
        #print c.v
        if c.v == N-1:
            break
        v = c.v+1

        while v<=c.v+6 and v < N:
            if not visited[v]:
                a = Cell(-1, c.dist+1)

                if move[v] != -1:
                    a.v = move[v]
                    visited[a.v] = True
                else:
                    a.v = v
                visited[v] = True
                q.append(a)
            v += 1
    print c.dist

N = 30
move = [-1 for _ in range(N)]

move[2] = 21
move[4] = 7
move[10] = 25
move[19] = 28

move[16] = 3
move[18] = 6
move[20] = 8
move[26] = 0

SnakeLadder(move)
