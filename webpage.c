#include <stdio.h>
#include <stdlib.h>

struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *current = NULL;
void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void visitPage(char url[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    copyString(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        current->next = newNode;
    }
    current = newNode;

    printf("Visited: %s\n", url);
}
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back!\n");
    } else {
        current = current->prev;
        printf("Went back to: %s\n", current->url);
    }
}
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward!\n");
    } else {
        current = current->next;
        printf("Went forward to: %s\n", current->url);
    }
}

void displayCurrentPage() {
    if (current == NULL) {
        printf("No page visited yet!\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n===== Browser Menu =====\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                printf("Exiting \n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
