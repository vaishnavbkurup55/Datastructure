#include <stdio.h>
#include <stdlib.h>

#define Max 10
int stack[Max];
int top = -1;

void push(int item) {
    if (top == Max - 1) {
        printf("\nStack overflow!");
        return;
    }
    stack[++top] = item;
    printf("\n%d pushed to stack", item);
}

void pop() {
    if (top == -1) {
        printf("\nStack underflow!");
        return;
    }
    printf("\n%d popped from stack", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("\nStack is empty!");
        return;
    }
    printf("\nTop element is %d", stack[top]);
}

void display() {
    if (top == -1) {
        printf("\nStack is empty!");
        return;
    }
    printf("\nStack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]); 
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n\nStack Operation Menu:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input format!");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}

