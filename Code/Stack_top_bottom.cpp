#include <iostream>
// Last in first out
using namespace std;
class stack
{
public:
    int size;
    int top;
    int *arr;
};
// 1 value in if statements means true, and 0 means false

int isEmpty(stack *ptr)
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
int isFull(stack *ptr)
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

void push(stack *ptr, int value)
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

void display(stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf("%d\t", ptr->arr[i]);
    }
    printf("\n");
}

int stackTop(stack *sp)
{
    return sp->arr[sp->top];
}
int stackBottom(stack *sp)
{
    return sp->arr[0];
}
int main()
{
    stack *sp = new stack;
    sp->size = 4;
    sp->top = -1;
    sp->arr = new int[sp->size];
    // Operation Push
    push(sp, 40);
    push(sp, 60);
    push(sp, 30);
    push(sp, 10);
    display(sp);

    cout << "The topmost value of this stack is " << stackTop(sp) << endl;
    cout << "The bottommost value of this stack is " << stackBottom(sp) << endl;

    return 0;
}