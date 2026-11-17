#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};


struct node *head = NULL;
struct node *rear = NULL;

void enqueue() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\n NO SPACE AVAILABLE \n");
        return;
    }
    newnode->link = NULL;
    printf("\n ENTER THE ELEMENT TO INSERT: ");
    scanf("%d", &newnode->data);
    
    
    if (head == NULL) {
        head = newnode;
        rear = newnode;
    } else {
        rear->link = newnode;
        rear = newnode;
    }
    printf("\n %d ELEMENT INSERTED SUCCESSFULLY \n", newnode->data);
}

void dequeue() {
    struct node *temp = head;
    if (head == NULL) {
        printf("\n NO ELEMENTS \n");
        return;
    }
    printf("\n %d IS DELETED \n", temp->data);
    head = temp->link;
    
    
    if (head == NULL) {
        rear = NULL;
    }
    
    free(temp);
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("\n NO ELEMENTS\n");
        return;
    }
    printf("\n ELEMENTS IN QUEUE ARE: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void search() {
    struct node *temp = head;
    int key, pos = 1, found = 0; 
    if (head == NULL) {
        printf("\n QUEUE EMPTY\n");
        return;
    }
    printf("\n ENTER THE ELEMENT TO SEARCH: ");
    scanf("%d", &key);
    
    while (temp != NULL) {
        if (temp->data == key) {
            printf("\n %d ELEMENT FOUND AT POSITION %d \n", temp->data, pos);
            found = 1;
        }
        temp = temp->link;
        pos++;
    }
    if (!found) {
        printf("\n ELEMENT NOT FOUND\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n *****QUEUE*****\n");
       
        printf(" 1 -> Enqueue()\n 2 -> Dequeue()\n 3 -> Display()\n 4 -> Search()\n 5 -> EXIT\n");
        printf("\n ENTER THE CHOICE: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: search();  break;
            case 5: printf("\n EXIT \n"); break;
            default: printf("Enter a valid Choice\n");
        }
    } while (choice != 5);
    
    return 0;
}

