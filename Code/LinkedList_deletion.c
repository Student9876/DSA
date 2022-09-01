#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *deleteFirst(struct Node *head)
{
    struct Node *p;
    p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q;
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    // In this loop q will move towards the end node untill q->next is not become NULL
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteElement(struct Node *head, int element)
{
    struct Node *p = head;
    struct Node *q = head->next;
    // To prevent the while loop to go infinite for searching the element
    while (q->data != element && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == element)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 6;
    head->next = second;

    // link second and third nodes
    second->data = 15;
    second->next = third;

    // Link third and forth nodes
    third->data = 56;
    third->next = fourth;
    // Link fourth and fifth nodes
    fourth->data = 33;
    fourth->next = fifth;
    // Link fifth and sixth nodes
    fifth->data = 22;
    fifth->next = sixth;

    // Terminate the list at the sixth node
    sixth->data = 23;
    sixth->next = NULL;

    printf("Linked List Before Deletion \n");
    linkedListTraversal(head);

    // For deleting first element of a linked list
    head = deleteFirst(head);

    printf("Linked List After Deletion of First Node \n");
    linkedListTraversal(head);

    // For deleting an element at a certain index
    int index = 2;
    printf("Linked List After Deletion of the node at index %d  \n", index);
    head = deleteAtIndex(head, index);
    linkedListTraversal(head);

    // For deleting the last node
    printf("Linked List After Deletion of the last node \n");
    head = deleteLast(head);
    linkedListTraversal(head);

    // For deleting an element
    int element = 56;
    printf("Linked List After Deletion of the element %d \n", element);
    head = deleteElement(head, element);
    linkedListTraversal(head);

    return 0;
}