#include <stdio.h>
#include <stdlib.h>
// Using this variables as global because then changes made in this variables is going to change globally
struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        // This case is so rare that if your memory become full then it will happen
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            // This means the queue was empty and we are adding a first Node
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list!!\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    // make this variables global because functions aren't returning anything.
    // struct Node *f = NULL;
    // struct Node *r = NULL;
    linkedListTraversal(f);
    printf("Dequeueing Element:%d\n", dequeue());
    enqueue(34);
    enqueue(23);
    enqueue(5);
    enqueue(7);
    linkedListTraversal(f);
    printf("Dequeueing Element:%d\n", dequeue());
    printf("Dequeueing Element:%d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}