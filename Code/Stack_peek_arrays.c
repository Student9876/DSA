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

/*
for a 3 length stack
    Position(i)        Array_Index
      1                 2
      2                 1
      3                 0

So Relation of Array_Index with position is "Array_Index = Top -i + 1"

*/
// peek function in stack
int peek(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
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

    // Lets peek
    printf("Value is : %d\n", peek(sp, 2));

    // Printing entire stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }

    return 0;
}