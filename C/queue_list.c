#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// 入队操作
void enqueue(Queue *queue, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        exit(-1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    Node *temp = queue->front;
    int value = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return value;
}

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    return queue->front->data;
}

void test_initQueue()
{
    Queue queue;
    initQueue(&queue);
    if (queue.front == NULL && queue.rear == NULL)
    {
        printf("initQueue passed\n");
    }
    else
    {
        printf("initQueue failed\n");
        exit(-1);
    }
}

void test_isEmpty()
{
    Queue queue;
    initQueue(&queue);
    if (!isEmpty(&queue))
    {
        printf("isEmpty failed\n");
        exit(-1);
    }
    enqueue(&queue, 1);
    if (isEmpty(&queue))
    {
        printf("isEmpty failed\n");
        exit(-1);
    }
    printf("isEmpty passed\n");
}

void test_enqueue()
{
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 1);
    if (queue.front->data != 1 || queue.rear->data != 1)
    {
        printf("enqueue failed\n");
        exit(-1);
    }
    enqueue(&queue, 2);
    if (queue.rear->data != 2)
    {
        printf("enqueue failed\n");
        exit(-1);
    }
    printf("enqueue passed\n");
}

void test_dequeue()
{
    Queue queue;
    initQueue(&queue);
    if (dequeue(&queue) != -1)
    {
        printf("dequeue failed\n");
        exit(-1);
    }
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    if (dequeue(&queue) != 1)
    {
        printf("dequeue failed\n");
        exit(-1);
    }
    if (dequeue(&queue) != 2 || queue.front != NULL || queue.rear != NULL)
    {
        printf("dequeue failed: queue state not updated correctly\n");
        exit(-1);
    }
    printf("dequeue passed\n");
}

void test_peek()
{
    Queue queue;
    initQueue(&queue);
    if (peek(&queue) != -1)
    {
        printf("peek failed\n");
        exit(-1);
    }
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    if (peek(&queue) != 1)
    {
        printf("peek failed\n");
        exit(-1);
    }
    printf("peek passed\n");
}

int main()
{
    test_initQueue();
    test_isEmpty();
    test_enqueue();
    test_dequeue();
    test_peek();
    return 0;
}
