#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue *queue)
{
    return queue->rear == MAX - 1;
}

int isEmpty(Queue *queue)
{
    return queue->front == -1 || queue->front > queue->rear;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (queue->front == -1)
            queue->front = 0;
        queue->items[++queue->rear] = value;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        return queue->items[queue->front++];
    }
}

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    else
    {
        return queue->items[queue->front];
    }
}

void test_initQueue()
{
    Queue queue;
    initQueue(&queue);
    if (queue.front == -1 && queue.rear == -1)
    {
        printf("initQueue succeeded\n");
    }
    else
    {
        printf("initQueue failed\n");
        exit(-1);
    }
}

void test_isFull()
{
    Queue queue;
    initQueue(&queue);
    if (isFull(&queue) != 0)
    {
        printf("isFull failed: empty queue should not be full\n");
        exit(-1);
    }
    for (int i = 0; i < MAX; i++)
    {
        enqueue(&queue, i);
    }
    if (isFull(&queue) != 1)
    {
        printf("isFull failed: queue should be full\n");
        exit(-1);
    }
}

void test_isEmpty()
{
    Queue queue;
    initQueue(&queue);
    if (isEmpty(&queue) == 0)
    {
        printf("isEmpty failed: newly initialized queue should be empty\n");
        exit(-1);
    }
    enqueue(&queue, 1);
    if (isEmpty(&queue) != 0)
    {
        printf("isEmpty failed: queue with one element should not be empty\n");
        exit(-1);
    }
}

void test_enqueue()
{
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 1);
    if (queue.items[queue.front] != 1)
    {
        printf("enqueue failed at first element\n");
        exit(-1);
    }
    enqueue(&queue, 2);
    if (queue.items[queue.rear] != 2)
    {
        printf("enqueue failed at second element\n");
        exit(-1);
    }
}

void test_dequeue()
{
    Queue queue;
    initQueue(&queue);
    if (dequeue(&queue) != -1)
    {
        printf("dequeue failed: should return -1 for empty queue\n");
        exit(-1);
    }
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    if (dequeue(&queue) != 1)
    {
        printf("dequeue failed: should return first enqueued element\n");
        exit(-1);
    }
    if (queue.items[queue.front] != 2)
    {
        printf("dequeue failed: front not updated correctly\n");
        exit(-1);
    }
}

void test_peek()
{
    Queue queue;
    initQueue(&queue);
    if (peek(&queue) != -1)
    {
        printf("peek failed: should return -1 for empty queue\n");
        exit(-1);
    }
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    if (peek(&queue) != 1)
    {
        printf("peek failed: should return first enqueued element\n");
        exit(-1);
    }
}

int main()
{
    test_initQueue();
    test_isFull();
    test_isEmpty();
    test_enqueue();
    test_dequeue();
    test_peek();

    return 0;
}
