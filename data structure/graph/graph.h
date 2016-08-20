#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct adjlistnode {
    int dest;
    struct adjlistnode *next; 
}AdjListNode;

typedef struct adjlist {
    AdjListNode *head;
}AdjList;

typedef struct graph {
    int V;
    AdjList *arr;
}Graph;

Graph* CreateGraph(int v);
AdjListNode* NewNode(int dest);
void AddEdge(Graph *g, int src, int dest);
void PrintGraph(Graph *g);

#endif
