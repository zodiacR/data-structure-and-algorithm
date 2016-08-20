#ifndef _QUEUE_H
#define _QUEUE_H

struct node;
typedef struct node* Node;
struct queue;
typedef struct queue* Queue;
typedef int Element;

Queue CreateQueue();
void Enqueue(Queue q, Element e);
Element Dequeue(Queue q);
Node dequeue(Queue q);
void DisposeQueue(Queue *q);

#endif

struct node{
    Element e;
    Node next;
};

struct queue{
    Node front;
    Node rear;
};
