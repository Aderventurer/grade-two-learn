#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("failed!\n");
        exit(-1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->top->data;
}

void test_initStack()
{
    Stack stack;
    initStack(&stack);
    if (stack.top == NULL)
    {
        printf("initStack passed\n");
    }
    else
    {
        printf("initStack failed\n");
        exit(-1);
    }
}

void test_isEmpty()
{
    Stack stack;
    initStack(&stack);
    if (!isEmpty(&stack))
    {
        printf("isEmpty failed\n");
        exit(-1);
    }
    push(&stack, 1);
    if (isEmpty(&stack))
    {
        printf("isEmpty failed\n");
        exit(-1);
    }
    printf("isEmpty passed\n");
}

void test_push()
{
    Stack stack;
    initStack(&stack);
    push(&stack, 1);
    if (stack.top->data != 1)
    {
        printf("push failed\n");
        exit(-1);
    }
    push(&stack, 2);
    if (stack.top->data != 2)
    {
        printf("push failed\n");
        exit(-1);
    }
    printf("push passed\n");
}

void test_pop()
{
    Stack stack;
    initStack(&stack);
    if (pop(&stack) != -1)
    {
        printf("pop failed\n");
        exit(-1);
    }
    push(&stack, 1);
    push(&stack, 2);
    if (pop(&stack) != 2)
    {
        printf("pop failed\n");
        exit(-1);
    }
    if (pop(&stack) != 1)
    {
        printf("pop failed\n");
        exit(-1);
    }
    printf("pop passed\n");
}

void test_peek()
{
    Stack stack;
    initStack(&stack);
    if (peek(&stack) != -1)
    {
        printf("peek failed\n");
        exit(-1);
    }
    push(&stack, 1);
    push(&stack, 2);
    if (peek(&stack) != 2)
    {
        printf("peek failed\n");
        exit(-1);
    }
    printf("peek passed\n");
}

int main()
{
    test_initStack();
    test_isEmpty();
    test_push();
    test_pop();
    test_peek();
    return 0;
}
