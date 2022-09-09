#include <iostream>
#include <string.h>

using namespace std;

class stack
{
public:
    int top;
    int size;
    char *arr;
};

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
void push(stack *ptr, char value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow!! Insertion not possible\n";
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
void pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow!! pop not possible\n";
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
    stack *sp = new stack;
    sp->top = -1;
    sp->size = strlen(exp);
    // printf("string length %d\n", sp->size);
    sp->arr = new char[sp->size];

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
    // In c++ containing the below expression in a char * is forbidden

    // It shows error -" ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]"

    // A correct solution is to copy the string literals into modifiable arrays:

    char exp[] = "((?>((?<c>)|[^()]+|)(?<-c>))*(?(c)(?!)))";
    if (parenthesisMatch(exp))
    {
        cout << "The parenthesis is matching\n";
    }
    else
    {
        cout << "The parenthesis is not matching\n";
    }
    return 0;
}