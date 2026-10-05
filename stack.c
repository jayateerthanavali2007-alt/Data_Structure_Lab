#include <stdio.h>
#include <stdlib.h>
#define N 5
int top = -1;
int stack[N];
void push(int item)
{
    if (top == N - 1)
    {
        printf("stack overflow");
        return;
    }
    top++;
    stack[top] = item;
}
int pop()
{
    if (top == -1)
    {
        printf("stack underflow");
        exit(0);
    }
    return stack[top--];
}
int peek()
{
    return stack[top];
}
void display()
{
    printf("stack\n");
    for (int i = top; i>=0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int main(){
    push(8);
    push(3);
    push(4);
    push(7);
    push(6);
    display();
    pop();
    peek();
    display();
    return 0;
}