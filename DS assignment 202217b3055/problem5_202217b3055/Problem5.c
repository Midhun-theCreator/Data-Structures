#include <stdio.h>
#include <stdlib.h> // For exit() function

#define SIZE 5

void main() {
    int queue[SIZE], choice = 1, front = 0, rear = 0, i, x = SIZE;

    printf("Queue using Array\n");
    printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");

    while (choice) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == SIZE) {
                    printf("\nQueue is Full");
                } else {
                    printf("\nEnter a number: ");
                    scanf("%d", &queue[rear++]);
                }
                break;

            case 2:
                if (front == rear) {
                    printf("\nQueue is Empty");
                } else {
                    printf("\nDeleted Element is %d", queue[front++]);
                }
                break;

            case 3:
                printf("\nQueue Elements are:\n");
                if (front == rear) {
                    printf("\nQueue is Empty");
                } else {
                    for (i = front; i < rear; i++) {
                        printf("%d\n", queue[i]);
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong Choice: please see the options\n");
        }
    }
}
