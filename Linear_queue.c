#include <stdio.h>
#define MAX 5
int queue[MAX];
int rear = -1;
int front = -1;
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("queue is full");
    }
    else
    {   if(rear==-1 && front==-1){
            front=0;
        }
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if ((rear == -1 && front == -1) || front > rear)
    {
        printf("queue empty");
    }
     else if(front==rear){
        printf("\n%d is removed\n",queue[front]);
        rear=front=-1;
    }
    else
    {
        printf("\n%d is removed\n",queue[front]);
        front++;
    }
}

void display()
{
    printf("\nQueue\n");
    if ((rear == -1 && front == -1) || front > rear)
    {   
        printf("queue empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    int choice,found=1;
    while(found){
    printf("\nMenu:\n");
    printf("1:enqueue(item)\n");
    printf("2:dequeue()\n");
    printf("3:display()\n");
    printf("4:Exit\n");
    printf("Enter your wish:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            int item;
            printf("Enter value to insert:");
            scanf("%d",&item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            found = 0;
            break;
        default:
            printf("Invalid entry\n");
    }
}
    return 0;
}