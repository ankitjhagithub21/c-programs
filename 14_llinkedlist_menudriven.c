#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}


struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}


struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return head;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    return head;
}


void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Delete a node\n");
        printf("5. Display the linked list\n");
        printf("6. Count nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 5:
                printf("Linked List: ");
                displayList(head);
                break;
            case 6:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
