#include <stdio.h>
#include <stdlib.h>
// Last in first out
struct stack
{
    int size;
    int top;
    int *arr;
};
// 1 value in if statements means true, and 0 means false

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!! Insertion not possible\n");
    }
    else
    {
        printf("%d pushed successfully\n", value);
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

void display(struct stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf("%d\t", ptr->arr[i]);
    }
    printf("\n");
}

int stackTop(struct stack * sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack * sp){
    return sp->arr[0];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 4;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    // Operation Push
    push(sp, 40);
    push(sp, 60);
    push(sp, 30);
    push(sp, 10);
    display(sp);

    printf("The topmost value of this stack is %d\n",stackTop(sp));
    printf("The bottommost value of this stack is %d\n",stackBottom(sp));
    return 0;
}