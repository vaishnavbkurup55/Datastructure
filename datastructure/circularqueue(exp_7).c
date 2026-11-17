#include <stdio.h>

#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    if ((rear + 1) % MAX == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow \n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        printf("%d inserted into the queue.\n", item);
    }
}

void dequeue() {
    if (isEmpty()) { 
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element is %d\n", queue[front]);
        
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty \n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) 
                break;
            i = (i + 1) % MAX; 
        }
        printf("\n");
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty \n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

void search() {
    int key, i, found = 0;
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    
    i = front;
    do {
        if (queue[i] == key) {
            printf("\nElement %d found at index position %d.\n", key, i);
            found = 1;
            break;
        }
        i = (i + 1) % MAX; 
    } while (i != (rear + 1) % MAX); 
    
    if (!found) {
        printf("\nElement %d not found in the queue.\n", key);
    }
}

int main() {
    int choice, item;
    do {
        printf("\n-- Circular Queue Operations--\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                search();
                break;
            case 6:
                printf("Program Ended \n");
                break;
            default:
                printf("Invalid Choice \n");
        }
    } while (choice != 6); 
    
    return 0;
}

