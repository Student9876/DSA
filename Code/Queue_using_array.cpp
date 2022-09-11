#include <iostream>
using namespace std;

template <class T>
class queue
{
public:
    int size;
    int f = -1;
    int r = -1;
    int count = 0;
    T *arr;
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
    void enqueue(T val)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
        }
        r++;
        arr[r] = val;
    }
    T dequeue()
    {
        int a = -1;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        f++;
        count++;
        a = arr[f];
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
    queue<int> q;
    q.size = 10;
    // q.f = q.r = -1;
    q.arr = new int(q.size);

    // Enqueue few elements
    q.enqueue(12);
    q.enqueue(43);
    q.enqueue(36);
    q.enqueue(56);

    q.display();

    // Dequeuing element
    cout << "Dequeued Element: " << q.dequeue() << endl;
    cout << "Dequeued Element: " << q.dequeue() << endl;

    q.display();
    return 0;
}