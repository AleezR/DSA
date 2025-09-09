#include <stdio.h>
#define MAX_SIZE 5

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;
    int operation, item, i;

    while(8) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your Operation: ");
        scanf("%d", &operation);

        if (operation == 1) {
           if (rear == MAX_SIZE - 1) {
                printf("Queue is full.\n");
            } else {
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                if (front == -1) {
                    front = 0;
                }
                rear++;
                queue[rear] = item;
                printf("%d inserted into queue.\n", item);
            }
         } else if (operation == 2) {
            if (front == -1 || front > rear) {
                printf("Queue is empty.\n");
            } else {
                printf("Element deleted: %d\n", queue[front]);
                front++;
                if (front > rear) {
                    front = rear = -1;
                }
            }
            
            } else if (operation == 3) {
           
            if (front == -1 || front > rear) {
                printf("Queue is empty.\n");
            } else {
                printf("Queue elements: ");
                for (i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }

        } else if (operation == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
