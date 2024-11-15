#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack->items[++stack->top] = value;
    }
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return stack->items[stack->top--];
    }
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    else
    {
        return stack->items[stack->top];
    }
}

void test_initStack()
{
    Stack stack;
    initStack(&stack);
    if (stack.top == -1)
    {
        printf("initStack successed");
    }
    else
    {
        printf("initStack failed");
        exit(-1);
    }
}

void test_isFull()
{
    Stack stack;
    initStack(&stack);
    if (isFull(&stack) != 0)
    {
        exit(-1);
    }
    for (int i = 0; i < MAX; i++)
    {
        push(&stack, i);
    }
    if (isFull(&stack) != 1)
    {
        exit(-1);
    }
}

void test_isEmpty()
{
    Stack stack;
    initStack(&stack);
    if (isEmpty(&stack) == 0)
    {
        exit(-1);
    }
}

void test_push()
{
    Stack stack;
    initStack(&stack);
    push(&stack, 1);
    if (stack.items[stack.top] != 1)
    {
        exit(-1);
    }
    push(&stack, 2);
    if (stack.items[stack.top] != 2)
    {
        exit(-1);
    }
}

void test_pop()
{
    Stack stack;
    initStack(&stack);
    if (pop(&stack) != -1)
    {
        exit(-1);
    }
    push(&stack, 1);
    push(&stack, 2);
    if (stack.items[stack.top] != 2)
    {
        exit(-1);
    }
    pop(&stack);
    if (stack.items[stack.top] != 1)
    {
        exit(-1);
    }
}

void test_peek()
{
    Stack stack;
    initStack(&stack);
    if (peek(&stack) != -1)
    {
        exit(-1);
    }
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    if (peek(&stack) != 3)
    {
        exit(-1);
    }
}

int main()
{
    test_initStack();
    test_isFull();
    test_isEmpty();
    test_push();
    test_pop();
    test_peek();
    return 0;
}
