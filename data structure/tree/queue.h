#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"
struct queue;
typedef struct queue Queue;
typedef Node Object; 
Queue* CreateQueue(int max_size);
void Enqueue(Queue *q, Object* e);
Object* Dequeue(Queue *q);
int IsFull(Queue *q);
int IsEmpty(Queue *q);
Queue* DisposeQueue(Queue* q);
#endif

struct queue{
    int front;
    int rear;
    int size;
    int capacity;
    Object** q;
};
