//
// Created by ashik on 9/18/2023.
//
#include<stdio.h>
#define Max 3
int stack[Max];
int top=-1;
void push(int value) //stack value insertion
{
    if(top>=Max-1)
    {
        printf("Overflow : Stack is full,can't push\n");
    }
    else
    {
        top++;
        stack[top]=value;
    }
}
void pop() //stack element deletion
{
    printf("After deletion (pop) :\n");
    if(top<0)
    {
        printf("Underflow : Stack is empty,can't pop\n");
        return;
    }
    else
    {
        top--;
    }
}
void show()
{
    if(top<0)
    {
        printf("There is no element in the stack\n");
    }
    else
    {
        printf("Stack is :\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d index value is %d\n",i,stack[i]);
        }
    }

}
int main()
{
    push(5);
    push(10);
    push(100);
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
}
