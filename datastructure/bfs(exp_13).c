#include <stdio.h>

#define MAX 100 

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX] = {0};

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    int value = queue[front++];
    return value;
}

int isQueueEmpty() {
    if (front == -1 || front > rear)
        return 1;
    return 0;
}


void bfs(int adj[MAX][MAX], int start, int n) {
    int i;
    
    enqueue(start);
    visited[start] = 1;
    
    printf("BFS Traversal: ");
    
    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
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

    printf("Enter adjacency matrix (row by row):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
            
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    
    if (start < 0 || start >= n) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    
    bfs(adj, start, n);
    
    return 0;
}

