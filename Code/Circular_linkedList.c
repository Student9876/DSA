#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    // // Like this the loop will never start
    // while(ptr!=head){
    //     printf("Element is %d",ptr->data);
    //     ptr = ptr->next;
    // }

    // // This One time push works
    // printf("Element is %d\n", ptr->data);
    // ptr = ptr->next;

    // while (ptr != head)
    // {
    //     printf("Element is %d\n", ptr->data);
    //     ptr = ptr->next;
    // }

    // Do while loop works here smoothly
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = head;
    p->next = ptr;
    head = ptr;

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

    // Link sixth node with the head node
    sixth->data = 78;
    sixth->next = head;

    printf("Linked List before Insertion \n");
    linkedListTraversal(head);
    int element = 60;

    printf("Linked List After Insertion of the element %d \n", element);
    head = insertAtFirst(head, element);
    linkedListTraversal(head);

    
    element = 59;
    printf("Linked List After Insertion of the element %d \n", element);
    head = insertAtFirst(head, element);
    linkedListTraversal(head);
    return 0;
}