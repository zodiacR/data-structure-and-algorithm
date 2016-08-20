#!/usr/bin/python
#-*-coding:utf-8 -*-
#Author   : Zodiac
#Version  : 1.0
#Filename : bipartite.py
class Graph(object):
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def AddEdge(self, src, dest):
        self.adj[src].append(dest)
        self.adj[dest].append(src)

    def Bipartite(self, start):
        colors = [-1 for _ in range(self.V)]
        colors[start] = 1
        q = list()

        q.append(start)

        while q:
            u = q.pop(0)
            for v in self.adj[u]:
                if colors[v] == -1:
                    colors[v] = 1 - colors[u]
                    q.append(v)
                elif colors[v] == colors[u]:
                    return False

        return True

    def DFSBipartiteUtil(self, start, colors, color):
        colors[start] = color
        for u in self.adj[start]:
            if colors[u] == -1 and not self.DFSBipartiteUtil(u, colors, 1-color):
                return False
            elif colors[start] == colors[u]:
                return False

        return True

    def DFSBipartite(self, start):
        colors = [-1 for _ in range(self.V)]

        return self.DFSBipartiteUtil(start, colors, 0)
                    
#g = Graph(6)
#g.AddEdge(0, 1)
#g.AddEdge(1, 2)
#g.AddEdge(2, 3)
#g.AddEdge(3, 4)
#g.AddEdge(4, 5)
#g.AddEdge(5, 0)

#g = Graph(5)
#g.AddEdge(0, 1)
#g.AddEdge(1, 2)
#g.AddEdge(2, 3)
#g.AddEdge(3, 4)
#g.AddEdge(4, 0)

g = Graph(4)
g.AddEdge(0, 1)
g.AddEdge(1, 2)
g.AddEdge(1, 3)
g.AddEdge(2, 3)
g.AddEdge(3, 0)

if g.Bipartite(0):
    print "Yes"
else:
    print "No"
