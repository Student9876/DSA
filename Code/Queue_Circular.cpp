#include <iostream>
using namespace std;

template <class T>
class circularQueue
{
public:
    int size;
    int f;
    int r;
    T *arr;
    int isFull(circularQueue<T> *q)
    {
        if ((q->r + 1) % q->size == q->f)
        {
            return 1;
        }
        return 0;
    }
    int isEmpty(circularQueue<T> *q)
    {
        if (q->r == q->f)
        {
            return 1;
        }
        return 0;
    }
    void enqueue(circularQueue<T> *q, T val)
    {
        if (isFull(q))
        {
            cout << "This queue is full!!" << endl;
        }
        else
        {
            cout << "Enqueued Element: " << val << endl;
            q->r = (q->r + 1) % q->size;
            q->arr[q->r] = val;
        }
    }
    T dequeue(circularQueue<T> *q)
    {
        T a;
        if (isEmpty(q))
        {
            cout << "This queue is Empty!!" << endl;
        }
        else
        {
            q->f = (q->f + 1) % q->size;
            a = q->arr[q->f];
            return a;
        }
    }
};

int main()
{
    circularQueue<int> q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = new int[q.size];
    q.enqueue(&q, 12);
    q.enqueue(&q, 23);
    q.enqueue(&q, 41);
    q.enqueue(&q, 45);
    cout << "Dequeued Value: " << q.dequeue(&q) << endl;
    q.enqueue(&q, 45);
    return 0;
}