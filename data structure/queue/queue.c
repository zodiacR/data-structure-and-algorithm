#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue CreateQueue(){
    Queue q = (Queue)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void Enqueue(Queue q, Element e){
    Node node = (Node)malloc(sizeof(struct node));
    node->e = e;
    node->next = NULL;

    if(!q->rear) {
        q->rear = q->front = node;
        return;
    }

    q->rear->next = node;
    q->rear = node;
}

Node dequeue(Queue q){
    if (!q->front) return NULL;

    Node n = q->front;
    q->front = q->front->next;

    if (!q->front) q->rear = NULL;

    return n;
}

Element Dequeue(Queue q){
    Node n = dequeue(q);

    if (!n) return 0;

    Element e = n->e;
    free(n);

    return e;
}

void DisposeQueue(Queue *q){
    while((*q)->front) Dequeue(*q);

    free(*q);
    *q = NULL;
}

int main()
{
    Queue q = CreateQueue();
    Enqueue(q, 10);
    Enqueue(q, 20);
    Dequeue(q);
    Dequeue(q);
    Enqueue(q, 30);
    Enqueue(q, 40);
    Enqueue(q, 50);
    printf("Dequeued item is %d\n", Dequeue(q));
    printf("Dequeued item is %d\n", Dequeue(q));
    /*printf("Dequeued item is %d\n", Dequeue(q));*/

    DisposeQueue(&q);
    return 0;
}
