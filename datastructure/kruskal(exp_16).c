#include <stdio.h>
#include <stdlib.h>


int find(int i, int parent[]);
int uni(int i, int j, int parent[]);

int main() { 
    int i, j, a, b, u, v, n, ne = 1;
    int min, mincost = 0;
    int cost[10][10], parent[10] = {0}; 

    printf("\nImplementation of Kruskal's algorithm\n");
    printf("\nEnter the no of vertices (Max 9): ");
    if (scanf("%d", &n) != 1 || n >= 10 || n <= 0) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("\nEnter the cost adjacency matrix (use 0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; 
            }
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    
    
    while (ne < n) {
        min = 999; 
        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u, parent);
        v = find(v, parent);

        if (uni(u, v, parent)) {
            printf("%d edge (%d -> %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

int find(int i, int parent[]) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j, int parent[]) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

