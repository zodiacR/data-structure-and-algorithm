#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "graph.h"

Graph* CreateGraph(int v){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->V = v;
    g->arr = (AdjList*)malloc(sizeof(AdjList) * v);

    for (int i = 0; i < v ; i++) g->arr[i].head = NULL;

    return g;
}

AdjListNode* NewNode(int dest){
    AdjListNode* node = (AdjListNode*)malloc(sizeof(AdjListNode));
    node->dest = dest;
    node->next = NULL;

    return node;
}

void AddEdge(Graph *g, int src, int dest) {
    AdjListNode* node = NewNode(dest); 
    assert(node != NULL);

    node->next = g->arr[src].head;
    g->arr[src].head = node;

    node = NewNode(src); 
    assert(node != NULL);

    node->next = g->arr[dest].head;
    g->arr[dest].head = node;
}
void PrintGraph(Graph *g){
    for (int i = 0; i < g->V; i++){
        AdjListNode* tmp = g->arr[i].head;
        printf("%d: ", i);
        while (tmp){
            printf("%d->", tmp->dest); 
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main()
{
    // create the graph given in above fugure
    int V = 5;
    Graph* graph = CreateGraph(V);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    PrintGraph(graph);
 
    return 0;
}
