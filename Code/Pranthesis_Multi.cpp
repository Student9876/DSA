#include<iostream>
#include<string.h>
using namespace std;
class stack{
    public:
        int size;
        int top;
        char * arr;
};

int isEmpty(stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(stack * ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack * ptr, char val){
    if(isFull(ptr)){
        cout<<"Stack overflow!!"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(stack * ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Underflow!! Cannot pop"<<endl;
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b){
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
    
}

int parenthesisMatch(char *exp){
    stack * sp = new stack;
    sp->top = -1;
    sp->size = strlen(exp);
    sp->arr = new char[sp->size];
    char popped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i]== '(' || exp[i]== '{' || exp[i]== '['){
            push(sp, exp[i]);
        }
        else if( exp[i]== ')' || exp[i]== '}' || exp[i]== ']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main()

{
    char exp[100];
    cin>>exp;
    if (parenthesisMatch(exp))
    {
        cout<<"The parenthesis is balanced"<<endl;
    }
    else
    {
        cout<<"The parenthesis is not balanced"<<endl;
    }
    return 0;
}