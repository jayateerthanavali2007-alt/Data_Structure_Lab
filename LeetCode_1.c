#include <stdio.h>
#include <string.h>
#define MAX 10
int top = -1;
char stack[MAX];

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack undererflow\n");
        return -1;
    }
    return stack[top--];
}

int main()
{
    char word[MAX];
    char result[MAX];
    char ch;
    int i = 0, j = 0;
    printf("enter a word:");
    scanf("%s", word);
    printf("enter the character:");
    scanf(" %c", &ch);
    for (i = 0; word[i] != '\0'; i++)
    {
        push(word[i]);
        if (word[i] == ch)
        {
            break;
        }
    }
    int index = i + 1;
    while (top != -1)
    {
        result[j++] = pop();
    }
    for (int i = index; word[i] != '\0'; i++)
    {
        result[j++] = word[i];
    }
    result[j]='\0';
    printf("result:%s", result);
    return 0;
}
