#include <iostream>
using namespace std;

class DEqueue
{
public:
    int size;
    int *arr;
    int count = 0;
    int f = -1;
    int r = -1;
    int isEmpty()
    {
        if (f == r)
        {
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (r == size - 1)
        {
            return 1;
        }
        return 0;
    }
    void enqueueR(int val)
    {
        if (isFull())
        {
            cout << "This queue if Full. Insertion from Rear isn't possible" << endl;
        }
        else
        {
            cout << "Enqueuing value " << val << " in the rear has done sucessfully" << endl;
            r++;
            arr[r] = val;
        }
    }
    void enqueueF(int val)
    {
        if (isFull())
        {
            cout << "This queue if Full. Insertion from Front isn't possible" << endl;
        }
        else
        {
            cout << "Enqueuing value " << val << " in the front has done sucessfully" << endl;
            for (int i = r; i <= f; i++)
            {
                arr[i + 1] = arr[i];
            }
            arr[f] = val;
            count = f;
            f--;
        }
    }
    int dequeueF()
    {
        int a = -1;
        if (isEmpty())
        {
            cout << "This Queue is empty. Deletion from Front isn't possible" << endl;
        }
        else
        {
            f++;
            count++;
            a = arr[f];
        }
        return a;
    }
    int dequeueR()
    {
        int a = -1;
        if (isEmpty())
        {
            cout << "This Queue is empty. Deletion from rear isn't possible" << endl;
        }
        else
        {
            a = arr[r];
            r--;
        }
        return a;
    }
    void display()
    {
        for (int i = count; i <= r; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};

int main()
{
    DEqueue dq;
    // Initializing DEqueue
    dq.size = 10;
    dq.arr = new int(dq.size);

    // enqueuing from rear
    dq.enqueueR(5);
    dq.enqueueR(6);
    dq.enqueueR(7);

    dq.display();
    dq.enqueueR(8);
    dq.display();

    // dequeuing from front
    cout << "Dequeued Element from front is: " << dq.dequeueF() << endl;
    dq.display();

    // enqueuing from Front
    dq.enqueueF(3);
    dq.enqueueF(9);
    dq.display();

    // dequeuing from rear
    cout << "Dequeued Element from rear is: " << dq.dequeueR() << endl;
    cout << "Dequeued Element from rear is: " << dq.dequeueR() << endl;
    dq.display();
    return 0;
}