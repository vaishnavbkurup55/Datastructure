#include <stdio.h>

#define MAX 100 

int stack[MAX];
int top = -1;
int visited[MAX] = {0};

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}


void dfs_non_recursive(int adj[MAX][MAX], int start, int n) {
    int i;
    push(start);
    visited[start] = 1;
    printf("DFS Traversal (non-recursive): ");
    
    while (top != -1) {
        int current = pop();
        printf("%d ", current); 
        
        
        for (i = n - 1; i >= 0; i--) {
            if (adj[current][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    
    int n, adj[MAX][MAX], i, j, start;
    
    printf("Enter number of vertices (Max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n > MAX || n <= 0) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]); 
        }
    }
            
    printf("Enter starting vertex (0 to %d): ", n - 1);
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    
    dfs_non_recursive(adj, start, n);
    
    return 0;
}

