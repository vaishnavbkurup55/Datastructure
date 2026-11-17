#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
} *top = NULL;

void push() {
    struct node* n = malloc(sizeof(struct node));
    if (!n) {
        printf("\nSTACK OVERFLOW\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &n->data);
    n->link = top;
    top = n;
    printf("%d element inserted successfully\n", n->data);
}

void pop() {
    if (!top) {
        printf("\nSTACK UNDERFLOW\n");
        return;
    }
    struct node* t = top;
    top = t->link;
    printf("\n%d is popped\n", t->data);
    free(t);
}

void peek() {
    if (!top) {
        printf("\nStack is empty\n");
    } else {
        printf("\nTop element is %d\n", top->data);
    }
}

void display() {
    if (!top) {
        printf("\nStack is empty\n");
        return;
    }
    printf("Elements in stack: ");
    struct node* t = top;
    while (t != NULL) {
        printf("%d -> ", t->data); 
        t = t->link;
    }
    printf("NULL\n"); 
}

void search() {
    int key, pos = 1, found = 0;
    if (!top) {
        printf("\nStack is empty\n");
        return;
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    struct node* t = top;
    while (t != NULL) {
        if (t->data == key) {
            printf("%d found at position %d from top\n", key, pos);
            found = 1;
            break; 
        }
        t = t->link;
        pos++;
    }
    if (!found) {
        printf("%d not found in the stack\n", key);
    }
}

int main() {
    int choice;
    do {
        printf("\n**STACK OPERATION**");
        printf("\n1 -> push\n2 -> pop\n3 -> peek\n4 -> display\n5 -> search\n6 -> exit\n");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: search(); break;
            case 6: printf("\nExit\n"); break;
            default: printf("Enter a valid choice\n");
        }
    } while (choice != 6);

    return 0;
}

