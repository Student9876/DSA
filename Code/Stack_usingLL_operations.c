#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow !!\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1; // Assuming out stack has all Positive integers
    }
}

int stackTop(void)
{
    return top->data;
}
int stackBottom(void)
{
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
int main()
{

    // Pushing elements in Stack
    top = push(top, 78);
    top = push(top, 43);
    top = push(top, 3);
    linkedListTraversal(top);
    int position = 2;
    printf("Value at position %d is %d\n", position, peek(position));

    for (int i = 1; i <= 3; i++)
    {
        printf("Value at position %d is %d\n", i, peek(i));
    }

    // Using stackTop and stackBottom
    printf("Value at stackTop is %d\n", stackTop());
    printf("Value at stackBottom is %d\n", stackBottom());
    return 0;
}