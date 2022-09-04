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
void display(stack * ptr){
    for (int i = 0; i < ptr->top +1 ; i++)
    {
        cout<<ptr->arr[i]<<"\t";
    }
    cout<<endl;
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
int peek(stack *sp, int i)
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
    // Allocation memory of this class in heap
    stack * sp = new stack;
    sp->size = 4;
    sp->top = -1;
    sp->arr = new int[sp->size];
    // Operation Push
    push(sp, 40);
    push(sp, 60);
    push(sp, 30);
    push(sp, 10);
    display(sp);

 // Lets peek
    printf("Value is : %d\n", peek(sp, 2));

    // Printing entire stack 
    for (int j = 1; j <= sp->top+1; j++)
    {
        printf("The value at position %d is %d\n",j,peek(sp,j));
    }
    
    return 0;
}