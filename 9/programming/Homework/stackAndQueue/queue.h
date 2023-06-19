#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
    int data;
    struct QueueNode *next;
};

typedef struct
{
    struct QueueNode *front;
    struct QueueNode *rear;
    int size;
} Queue;

Queue initQueue();
int popQueue(Queue *queue);
void pushQueue(Queue *queue, int data);

#endif