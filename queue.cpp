#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert element
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d inserted\n", value);
    }
}

// Delete element
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("%d deleted\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Display elements
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();

    return 0;
}