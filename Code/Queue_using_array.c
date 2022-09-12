#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        printf("Enqueued Element: %d\n", val);
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}
int main()
{
    struct queue q;
    q.size = 3;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isEmpty(&q))
        printf("Queue is empty\n");
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 43);
    enqueue(&q, 36);

    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    // // Thats the problem with linear queue. Can be solved by Circular queue
    // enqueue(&q, 45); // This will print ' Queue is Full '. But actually queue is empty.

    // // below this 2 functions will run simultanously. Because both the front and rear are at the end and we cannot reuse them
    // if (isEmpty(&q))
    //     printf("Queue is empty\n");
    // if (isFull(&q))
    //     printf("Queue is Full\n");
    return 0;
}