#include <iostream>
using namespace std;
// Using Global Variables so that changes are made globally
class Node;
Node *f;
Node *r;

class Node
{
public:
    int data;
    Node *next;
    void enqueue(int val)
    {
        Node *n = new Node;
        if (n == NULL)
        {
            // This case is so rare that if your memory become full then it will happen
            cout << "Queue is Full !!" << endl;
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
        Node *ptr = f;
        if (f == NULL)
        {
            cout << "Queue is Empty !!" << endl;
        }
        else
        {
            f = f->next;
            val = ptr->data;
            free(ptr);
        }
        return val;
    }
    void linkedListTraversal(Node *ptr)
    {
        cout << "Printing the elements of this linked list!!" << endl;
        while (ptr != NULL)
        {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    // make this variables global because functions aren't returning anything.
    // Node *f = NULL;
    // Node *r = NULL;
    Node n;
    n.linkedListTraversal(f);
    cout << "Dequeueing Element: " << n.dequeue() << endl;
    n.enqueue(34);
    n.enqueue(23);
    n.enqueue(5);
    n.enqueue(7);
    n.linkedListTraversal(f);
    cout << "Dequeueing Element: " << n.dequeue() << endl;
    cout << "Dequeueing Element: " << n.dequeue() << endl;
    n.linkedListTraversal(f);
    return 0;
}