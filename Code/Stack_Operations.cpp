#include<iostream>
using namespace std;

class stack{
    public:
        int size;
        int top;
        int * arr;
};

int isFull(stack * ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

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

void push(stack * ptr, int value ){
    if(isFull(ptr)){
        cout<<"Stack Overflow !!"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
        cout<<value<<" pushed in the stack successfully"<<endl;
    }
}

void pop(stack * ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Underflow !!"<<endl;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        cout<<value<<" popped from the stack successfully"<<endl;
    }
}

void display(stack * ptr){
    for (int i = 0; i < ptr->top +1 ; i++)
    {
        cout<<ptr->arr[i]<<"\t";
    }
    cout<<endl;
}
int main()
{
    // Allocation memory of this class in heap
    stack * sp = new stack;
    sp->size = 4;
    sp->top = -1;
    sp->arr = new int[sp->size];
    cout<<"Stack has been created successfully "<<endl;
     // Functions to check whether the Stack is full or empty
    cout<<isFull(sp)<<endl;
    cout<<isEmpty(sp)<<endl;
    

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

    // // To see stack underflow
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // display(sp);
    return 0;
}