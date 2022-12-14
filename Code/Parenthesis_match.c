#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

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
void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!! Insertion not possible\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
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
        char val = ptr->arr[ptr->top];
        ptr->top--;
    }
}
int parenthesisMatch(char *exp)
{
    // Create and Initialize the stack

    // stack *sp; This will cause segmentaion fault( core dumped )
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = strlen(exp);
    // printf("string length %d\n", sp->size);
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{

    char *exp = "((?>((?<c>)|[^()]+|)(?<-c>))*(?(c)(?!)))";
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }
    return 0;
}