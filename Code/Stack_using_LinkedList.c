#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
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

int pop(struct Node **top)
{
    /*
    We are using address of address. So that if any changes made in top
    in this function, that will change the original top. Because changes made
    in a function has nothing to do with the main function until its being returned
    */
    if (isEmpty(*top))
    {
        printf("Stack Underflow !!\n");
    }
    else
    {
        struct Node *n = (*top);
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
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
int main()
{
    struct Node *top = NULL;

    // Pushing elements in Stack
    top = push(top, 78);
    top = push(top, 43);
    top = push(top, 3);
    linkedListTraversal(top);

    int element = pop(&top);
    printf("Popped element is: %d\n", element);
    linkedListTraversal(top);
    return 0;
}