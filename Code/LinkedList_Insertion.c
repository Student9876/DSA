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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    // After the loop get completed, p will be pointing an index before where we want to insert new node
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    // Head is not changing here. As the element is being inserted in an index.
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    ptr->data = data;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 6;
    head->next = second;

    // link second and third nodes
    second->data = 15;
    second->next = third;

    // Link third and forth nodes
    third->data = 56;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 23;
    fourth->next = NULL;

    linkedListTraversal(head);
    printf("\n\n");
    // This funtion is returning a new head
    head = insertAtFirst(head, 2);
    linkedListTraversal(head);

    // This function insertes an element at a certain index
    printf("\n\n");

    head = insertAtIndex(head, 69, 2);
    linkedListTraversal(head);

    // This function insertes an element at a certain index
    printf("\n\n");
    head = insertAtEnd(head, 98);
    linkedListTraversal(head);

    // // This function insertes an element after a certain Node
    // // Comment out previous insertion before executing this
    // printf("\n\n");
    // head = insertAfterNode(head, second, 345);
    // linkedListTraversal(head);

    return 0;
}
