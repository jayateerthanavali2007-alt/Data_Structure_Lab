#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}

int pop()
{
    if (top == -1)
    {
        printf("stack  underflow");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
  
        else if (ch == '(')
        {
            push(ch);
        }
  
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }

        else
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
