#include <stdio.h>
#include <stdlib.h> // For exit()

#define N 5

void enqueue(int queue[], int *rear, int value);
void dequeue(int queue[], int *front, int *rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[N];
    int choice = 1;
    int front = 0, rear = 0, value;

    printf("Queue using Array");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");

    while (choice != 4) {
        printf("\nEnter the Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == N) {
                    printf("\nQueue is Full");
                } else {
                    printf("\nEnter number to insert: ");
                    scanf("%d", &value);
                    enqueue(queue, &rear, value);
                }
                break;
            case 2:
                if (front == rear) {
                    printf("\nQueue is empty");
                } else {
                    dequeue(queue, &front, &rear);
                }
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("Wrong Choice: please see the options");
        }
    }

    return 0;
}

void enqueue(int queue[], int *rear, int value) {
    queue[*rear] = value;
    (*rear)++;
}

void dequeue(int queue[], int *front, int *rear) {
    printf("\nDeleted Element is %d", queue[*front]);
    (*front)++;
}

void display(int queue[], int front, int rear) {
    printf("\nQueue Elements are:\n");
    if (front == rear) {
        printf("\nQueue is Empty");
    } else {
        for (int i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

