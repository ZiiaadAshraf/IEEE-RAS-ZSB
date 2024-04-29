#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void push(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty, cannot delete\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    char command;

    while (1) {
        printf("Enter command (+ to add, - to delete, p to print, x to exit): ");
        scanf(" %c", &command);

        if (command == '+') {
            int data;
            printf("Enter data to add: ");
            scanf("%d", &data);
            push(&head, data);
        } else if (command == '-') {
            deleteNode(&head);
        } else if (command == 'p') {
            printLinkedList(head);
        } else if (command == 'x') {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

 return 0;
}