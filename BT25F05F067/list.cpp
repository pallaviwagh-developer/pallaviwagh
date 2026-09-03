#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(int data) {
    struct Node *newNode = createNode(data);

    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Insert at ending
void insertEnding(int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at ending.\n");
}

// Insert at a given position
void insertPosition(int data, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertBeginning(data);
        return;
    }

    newNode = createNode(data);
    temp = head;

    // Move to the node before the required position
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

// Delete at beginning
void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted node: %d\n", temp->data);

    free(temp);
}

// Delete at ending
void deleteEnding() {
    struct Node *temp;
    struct Node *prev;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    // If only one node exists
    if (head->next == NULL) {
        printf("Deleted node: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted node: %d\n", temp->data);

    free(temp);
}

// Delete at a given position
void deletePosition(int position) {
    struct Node *temp;
    struct Node *prev;
    int i;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist!\n");
        return;
    }

    prev->next = temp->next;

    printf("Deleted node: %d\n", temp->data);

    free(temp);
}

// Display beginning node
void displayBeginning() {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Beginning node = %d\n", head->data);
}

// Display node at a given position
void displayPosition(int position) {
    struct Node *temp;
    int i;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist!\n");
        return;
    }

    printf("Node at position %d = %d\n", position, temp->data);
}

// Display ending node
void displayEnding() {
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Ending node = %d\n", temp->data);
}

// Display complete linked list
void displayList() {
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice;
    int data;
    int position;

    while (1) {
        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1.  Insert at Beginning\n");
        printf("2.  Insert at Position\n");
        printf("3.  Insert at Ending\n");
        printf("4.  Delete at Beginning\n");
        printf("5.  Delete at Position\n");
        printf("6.  Delete at Ending\n");
        printf("7.  Display Beginning Node\n");
        printf("8.  Display Node at Position\n");
        printf("9.  Display Ending Node\n");
        printf("10. Display Complete List\n");
        printf("11. Exit\n");
        printf("======================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(data, position);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnding(data);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &position);

                deletePosition(position);
                break;

            case 6:
                deleteEnding();
                break;

            case 7:
                displayBeginning();
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d", &position);

                displayPosition(position);
                break;

            case 9:
                displayEnding();
                break;

            case 10:
                displayList();
                break;

            case 11:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
