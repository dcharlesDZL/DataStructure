/*
队列为先进先出
*/
#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
#define QUEUE_INITSIZE 50
#define QUEUE_INCREMENT 2
typedef int QueueElement;
typedef struct _Queue
{
    int queuesize;
    QueueElement *base;
    QueueElement *top;
} Queue;

Status InitQueue(Queue *q)
{
    q->base = (QueueElement *)malloc(QUEUE_INITSIZE * sizeof(QueueElement));
    if (!q->base)
    {
        printf("error: OVERFLOW");
        exit(OVERFLOW);
    }
    q->top = q->base;
    q->queuesize = QUEUE_INITSIZE;
    return OK;
}

Status Push(Queue *q, QueueElement e)
{
    if (!q)
        exit(ERROR);
    if (q->top == q->base)
    {
        printf("queue is empty");
        return ERROR;
    }
    *q->top++ = e;
    return OK;
}

QueueElement Pop(Queue *q)
{
    QueueElement e;
    if (!q)
        exit(ERROR);
    if (q->top == q->base)
    {
        printf("queue is empty");
        return ERROR;
    }
    e = *q->base++;
    return e;
}

int main()
{

    return 0;
}