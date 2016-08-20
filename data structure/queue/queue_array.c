#include "queue_array.h"
#include <stdlib.h>
#include <stdio.h>


Queue CreateQueue(unsigned capacity){
    Queue q = (Queue)malloc(sizeof(struct QueueRecord));
    q->front = q->size = 0;
    q->capacity = capacity;
    q->rear = capacity-1;
    q->queue = (Element *)malloc(sizeof(Element) * capacity);

    return q;
}

int IsEmpty(Queue q){
    return (q->size == 0);
}

int IsFull(Queue q){
    return (q->size == q->capacity);
}

void Enqueue(Queue q, Element e){
    if (IsFull(q)) return;

    q->rear = (q->rear + 1) % q->capacity;
    q->queue[q->rear] = e;
    q->size = q->size + 1;
}

Element Dequeue(Queue q){
    if (IsEmpty(q)) return 0;

    Element e = q->queue[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;

    return e;
}

Element front(Queue q){
    if (IsEmpty(q)) return 0;

    return q->queue[q->front];
}

Element rear(Queue q){
    if (IsEmpty(q)) return 0;

    return q->queue[q->rear];
}

void DisposeQueue(Queue *q){
    free((*q)->queue);
    free(*q);

    q = NULL;
}

int main()
{
    Queue queue = CreateQueue(100);
 
    Enqueue(queue, 10);
    Enqueue(queue, 20);
    Enqueue(queue, 30);
    Enqueue(queue, 40);
 
    printf("%d Dequeued from queue\n", Dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    DisposeQueue(&queue);
 
    return 0;
}
