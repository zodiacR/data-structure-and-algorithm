#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

typedef int Element;
struct QueueRecord;
typedef struct QueueRecord* Queue;
Queue CreateQueue(unsigned capacity);
void DisposeQueue(Queue *q);
int IsEmpty(Queue q);
int IsFull(Queue q);
void Enqueue(Queue q, Element e);
Element Dequeue(Queue q);
Element front(Queue q);
Element rear(Queue q);

#endif

struct QueueRecord{
    int front;
    int rear;
    int size;
    int capacity;
    Element *queue;
};
