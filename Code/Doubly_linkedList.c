#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void forwardTraversal(struct Node *head)
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("Element is %d\n", p->data);
        p = p->next;
    }
}
void reverseTraversal(struct Node *last)
{
    struct Node *p = last;
    while (p != NULL)
    {
        printf("Element is %d\n", p->data);
        p = p->prev;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking of head
    head->next = NULL;
    head->data = 5;
    head->next = second;

    // linking second node
    second->prev = head;
    second->data = 10;
    second->next = third;
    // linking third node
    third->prev = second;
    third->data = 15;
    third->next = fourth;
    // linking fourth node
    fourth->prev = third;
    fourth->data = 20;
    fourth->next = NULL;
    printf("This is forward traversal of Doubly Linked List \n");
    forwardTraversal(head);
    printf("\n\n");
    printf("This is reverse traversal of Doubly Linked List \n");
    reverseTraversal(fourth);

    return 0;
}