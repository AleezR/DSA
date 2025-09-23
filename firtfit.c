#include <stdio.h>
#include <stdlib.h>
typedef struct Block {
    int start_address;
    int size;
    struct Block* next;
    struct Block* prev;
} Block;

Block* head = NULL; 
Block* create_block(int start, int size) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    if (new_block == NULL) {
        printf("Memory allocation for block failed\n");
        exit(1);
    }
    new_block->start_address = start;
    new_block->size = size;
    new_block->next = NULL;
    new_block->prev = NULL;
    return new_block;
}
void add_block(int start, int size) {
    Block* new_block = create_block(start, size);
    if (head == NULL) {
        head = new_block;
        return;
    }
    Block* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_block;
    new_block->prev = temp;
}
void display_free_blocks() {
    printf("Free Memory Blocks:\n");
    Block* temp = head;
    while (temp != NULL) {
        printf("Start: %d, Size: %d\n", temp->start_address, temp->size);
        temp = temp->next;
    }
    printf("\n");
}
void first_fit_allocate(int request_size) {
    Block* temp = head;
    while (temp != NULL) {
        if (temp->size >= request_size) {
            printf("Memory allocated at address: %d\n", temp->start_address);

            if (temp->size == request_size) {
                if (temp->prev == NULL && temp->next == NULL) {
                    head = NULL;
                }
                else if (temp->prev == NULL) {
                    head = temp->next;
                    head->prev = NULL;
                }
                else if (temp->next == NULL) {
                    temp->prev->next = NULL;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                free(temp);
            }
            else {
                temp->start_address += request_size;
                temp->size -= request_size;
            }
            return;
        }
        temp = temp->next;
    }
    printf("Allocation failed: No sufficient memory block available\n");
}
int main() {
    add_block(1000, 200);
    add_block(1200, 500);
    add_block(1700, 300);
    add_block(2000, 600);

    display_free_blocks();

    printf("Allocate process of size 250\n");
    first_fit_allocate(250);
    display_free_blocks();

    printf("Allocate process of size 100\n");
    first_fit_allocate(100);
    display_free_blocks();

    printf("Allocate process of size 500\n");
    first_fit_allocate(500);
    display_free_blocks();

    printf("Allocate process of size 700\n");
    first_fit_allocate(700);
    display_free_blocks();

    return 0;
}

