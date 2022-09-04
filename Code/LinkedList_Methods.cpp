// Contents
/*
******Linked list Methods********
1. Linked List insertions
2. Linked List deletion
3. Linked List traversal
*/

#include <iostream>
using namespace std;

class Node
{
public:
    class Node *next;
    int data;
};

Node *insertAtFirst(Node *head, int data)
{
    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

Node *insertAtIndex(Node *head, int data, int index)
{
    Node *ptr = new Node;
    Node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head; // head is not changing
}

Node *insertAtEnd(Node *head, int data)
{
    Node *ptr = new Node;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

Node *insertAfterNode(Node *head, Node *prevNode, int data)
{
    Node *ptr = new Node;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    ptr->data = data;
    return head;
}

void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node *deleteFromFirst(Node *head)
{
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *deleteAtIndex(Node *head, int index)
{
    Node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

Node *deleteLast(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Cannot Delete First element
Node *deleteElement(Node *head, int element)
{
    Node *p = head;
    Node *q = head->next;
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
    // Allocating memory in heap
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

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

    // Insert at first
    cout << "After Inserting at first " << endl;
    int element;
    element = 60;
    head = insertAtFirst(head, element);
    linkedListTraversal(head);

    // Insert at an index
    int index;
    index = 2;
    element = 55;
    head = insertAtIndex(head, element, index);
    cout << "After Insetring " << element << " at an index " << index << endl;
    linkedListTraversal(head);

    // Insert at the end
    element = 108;
    cout << "After Insetring " << element << " at the last" << endl;
    head = insertAtEnd(head, element);
    linkedListTraversal(head);

    // Insert after a Node
    // It works partially
    element = 37;
    cout << "After Insetring " << element << " after a Node" << endl;
    head = insertAfterNode(head, second, element);
    linkedListTraversal(head);

    // Linked List removal
    // Delete form first
    cout << "After deleting form the first" << endl;
    head = deleteFromFirst(head);
    linkedListTraversal(head);

    // delete from an index
    index = 3;
    cout << "After deleting form the index " << index << endl;
    head = deleteAtIndex(head, index);
    linkedListTraversal(head);

    // delete last node
    cout << "After deleting form the last " << endl;
    head = deleteLast(head);
    linkedListTraversal(head);

    // Delete an element
    element = 15;
    cout << "After deleting element " << element << endl;
    head = deleteElement(head, element);
    linkedListTraversal(head);

    return 0;
}