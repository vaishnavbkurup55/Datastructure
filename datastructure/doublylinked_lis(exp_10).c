#include <stdio.h>
#include <stdlib.h> // Standard header; removed old <malloc.h>

struct node {
    int data;
    struct node *Llink;
    struct node *Rlink;
};

struct node *head = NULL;

void insertFirst() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\n No Space available\n");
        return;
    }
    newnode->Llink = NULL;
    newnode->Rlink = NULL;
    printf("\n Enter the element to insert: ");
    scanf("%d", &newnode->data);
    
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->Rlink = head;
        head->Llink = newnode;
        head = newnode;
    }
    printf("\n %d inserted successfully\n", newnode->data);
}

void insertLast() {
    struct node *newnode, *temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\n Error: No space available for a new node.\n");
        return;
    }
    newnode->Llink = NULL;
    newnode->Rlink = NULL;
    printf("\n Enter the element to insert: ");
    scanf("%d", &newnode->data);
    
    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->Rlink != NULL) {
            temp = temp->Rlink;
        }
        temp->Rlink = newnode;
        newnode->Llink = temp;
    }
    printf("%d inserted successfully\n", newnode->data);
}

void insertLocation() {
    struct node *newnode, *temp = head, *nxt;
    int key;
    
    if (head == NULL) {
        printf("\n List is empty \n");
        return; 
    }
    
    printf("\n Enter the key after which you want to insert the element: ");
    scanf("%d", &key);
    
    while (temp != NULL && temp->data != key) {
        temp = temp->Rlink;
    }
    
    if (temp == NULL) {
        printf("\n NO ELEMENT FOUND \n");
        return;
    }
    

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\n Error: No space available for a new node.\n");
        return;
    }
    newnode->Llink = NULL;
    newnode->Rlink = NULL;
    
    printf("\n Enter the element to insert: ");
    scanf("%d", &newnode->data);
    
    if (temp->Rlink == NULL) {
        newnode->Llink = temp;
        temp->Rlink = newnode;
    } else {
        nxt = temp->Rlink;
        newnode->Llink = temp;
        newnode->Rlink = nxt;
        temp->Rlink = newnode;
        nxt->Llink = newnode;
    }
    printf("%d inserted successfully\n", newnode->data);
}

void deleteFirst() {
    struct node *temp = head, *nxt;
    if (head == NULL) {
        printf("\n LIST EMPTY \n");
        return;
    }
    printf("\n %d is deleted\n", temp->data);
    if (temp->Rlink == NULL) {
        head = NULL;
    } else {
        nxt = temp->Rlink;
        head = nxt;
        nxt->Llink = NULL;
    }
    free(temp);
}

void deleteLast() {
    struct node *temp = head, *nxt;
    if (head == NULL) {
        printf("\n LIST IS EMPTY \n");
        return;
    }
    if (temp->Rlink == NULL) {
        printf("\n %d is deleted\n", temp->data);
        head = NULL;
    } else {
        while (temp->Rlink != NULL) {
            temp = temp->Rlink;
        }
        printf("\n %d is deleted\n", temp->data);
        nxt = temp->Llink;
        nxt->Rlink = NULL;
    }
    free(temp);
}

void deleteLocation() {
    struct node *temp = head, *prev, *next;
    int key;
    if (head == NULL) {
        printf("\n LIST IS EMPTY \n");
        return;
    }
    printf("\n Enter the key which you want to delete: ");
    scanf("%d", &key);
    
    while (temp != NULL && temp->data != key) {
        temp = temp->Rlink;
    }
    
    if (temp == NULL) {
        printf("\n NO ELEMENT FOUND \n");
        return;
    }
    
    if (temp->Llink == NULL) {
        head = temp->Rlink;
        if (head != NULL) {
            head->Llink = NULL;
        }
    } else if (temp->Rlink == NULL) {
        temp->Llink->Rlink = NULL;
    } else {
        prev = temp->Llink;
        next = temp->Rlink;
        prev->Rlink = next;
        next->Llink = prev;
    }
    printf("%d Deleted successfully\n", temp->data);
    free(temp);
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("\n NO ELEMENTS IN LIST \n");
        return;
    }
    printf("\n ** ELEMENTS IN LIST ** \n");
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->Rlink;
    }
    printf("NULL\n");
}

void search() {
    int key, pos = 1, found = 0; 
    struct node *temp = head;
    if (head == NULL) {
        printf("\n LIST EMPTY \n");
        return;
    }
    printf("\n Enter the key to search: ");
    scanf("%d", &key);
    
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d is found at location %d\n", temp->data, pos);
            found = 1;
        }
        temp = temp->Rlink;
        pos++;
    }
    if (!found) {
        printf("\n ELEMENT NOT FOUND \n");
    }
}

int main() { 
    int choice;
    do {
        printf("\n***** DOUBLY LINKED LIST *****\n");
        printf("1 -> Insert First\n2 -> Insert Last\n3 -> Insert Location\n");
        printf("4 -> Delete First\n5 -> Delete Last\n6 -> Delete Location\n");
        printf("7 -> Search\n8 -> Display\n9 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insertFirst();     break;
            case 2: insertLast();      break;
            case 3: insertLocation();  break;
            case 4: deleteFirst();     break;
            case 5: deleteLast();      break;
            case 6: deleteLocation();  break;
            case 7: search();          break;
            case 8: display();         break;
            case 9: printf("\nEXIT\n"); break;
            default: printf("Enter a valid choice!\n"); break;
        }
    } while(choice != 9);
    
    return 0;
}

