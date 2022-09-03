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
        printf("\n");
    }
}
void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!! pop not possible\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d has been succesfully removed\n", val);
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
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 4;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created successfully \n");

    // Functions to check whether the Stack is full or empty
    printf("%d\n", isFull(sp));
    printf("%d\n", isEmpty(sp));

    // Operation Push
    push(sp, 40);
    display(sp);
    push(sp, 60);
    display(sp);
    push(sp, 30);
    display(sp);
    push(sp, 10);
    display(sp);
    push(sp, 100);
    display(sp);

    // // Operation Pop
    pop(sp);
    display(sp);
    pop(sp);
    display(sp);

    // To see stack underflow
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // display(sp);
    return 0;
}