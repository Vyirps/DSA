#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Stack *initialize();
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

int main()
{
    Stack *s = initialize();
    display(s);
    push(s, 1);
    display(s);
    push(s, 2);
    push(s, 3);
    display(s);
    printf("\nValue %d popped\n", pop(s));
    printf("\nValue %d at top\n", peek(s));
    display(s);
    printf("\nValue %d popped\n", pop(s));
    printf("\nValue %d popped\n", pop(s));
    printf("\nValue %d popped\n", pop(s));

}

Stack *initialize()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack * s)
{
    return false;
}

bool isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (isEmpty(s))
    {
        s->top = newNode;
        newNode->next = NULL;
        printf("\nNode with the value of %d is added at the start\n", value);
    }
    else
    {
        newNode->next = s->top;
        s->top = newNode;
        printf("\nNode with the value of %d is added as the top\n", value);
    }
}

int pop(Stack *s)
{
    if (!isEmpty(s))
    {
        Node *temp = s->top;
        int value = temp->data;
        s->top = s->top->next;
        free(temp);
        return value;
    }
    else
    {
        printf("\nStack is Empty cannot POP\n");
        return -1;
    }
}

int peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->top->data;
    }
    else
    {
        printf("\nStack is empty cannot PEEK\n");
        return -1;
    }
}

void display(Stack *s)
{
    if (!isEmpty(s))
    {
        printf("\n--- List ---\n");
            Node *temp = s->top;
        while (temp != NULL)
        {
            printf("\nNode is %d\n", temp->data);
            temp = temp->next;
        }
        free(temp);
    }
    else
    {
        printf("\nStack is empty cannot DISPLAY\n");
    }
}