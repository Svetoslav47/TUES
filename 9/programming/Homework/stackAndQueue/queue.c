#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue initQueue()
{
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    queue.size = 0;
    return queue;
}

int popQueue(Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->front->data;
    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

void pushQueue(Queue *queue, int data)
{
    struct QueueNode *node = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    node->data = data;
    node->next = NULL;
    if (queue->size == 0)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}
