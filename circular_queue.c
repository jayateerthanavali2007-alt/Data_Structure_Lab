#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

void insert(int item){
    if(front == ((rear + 1) % MAX)){
        printf("Queue overflow\n");
        return;
    }
    else if(front == -1){
        front = rear = 0;
        queue[rear] = item;
        printf("%d is inserted successfully\n", item);
    }
    else{
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        printf("%d is inserted successfully\n", item);
    }
}

void delete(){
    if(front == -1){
        printf("Queue underflow\n");
        return;
    }
    else if(front == rear){
        int d_item = queue[front];
        printf("%d is removed\n", d_item);
        front = rear = -1;
    }
    else{
        int d_item = queue[front];
        printf("%d is removed\n", d_item);
        front = (front + 1) % MAX;
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is: ");
    int i = front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear){
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(){
    int choice, num;
    printf("\nMENU\n");
    printf("1:insert\n2:delete\n3:display\n4:Exit\n");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(front == ((rear + 1) % MAX)){
                    printf("Queue overflow! Cannot insert more items.\n");
                } else {
                    printf("Enter number to insert: ");
                    scanf("%d", &num);
                    insert(num);
                }
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid entry\n");
        }
    }
}
