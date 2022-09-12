#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full, cannot enqueue %d\n", val);
    }
    else
    {
        printf("Enqueued Element: %d\n", val);
        // Circular Increment
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty, cannot dequeue\n");
    }
    else
    {
        // circular increment
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        return a;
    }
}
int main()
{
    struct circularQueue q;
    // Always there will be blank 1 block in Circular Queue
    q.size = 4; // We can input 3 elements
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isEmpty(&q))
        printf("Queue is empty\n");
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 43);
    enqueue(&q, 36);

    printf("Dequeuing element %d\n", dequeue(&q));

    // This will print queue is full and empty simultanously
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    // Thats the problem with linear queue. Can be solved by Circular queue
    enqueue(&q, 45); // This will print ' Queue is Full '. But actually queue is empty.

    if (isEmpty(&q))
        printf("Queue is empty\n");
    if (isFull(&q))
        printf("Queue is Full\n");
    return 0;
}