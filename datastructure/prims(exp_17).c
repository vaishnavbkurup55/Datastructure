#include <stdio.h>

int main() { 
    int a, b, u, v, n, i, j, ne = 1;
    int visited[10] = {0};
    int min, mincost = 0, cost[10][10];

    printf("\nEnter the number of nodes (Max 9): ");
    if (scanf("%d", &n) != 1 || n >= 10 || n <= 0) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    printf("\nEnter the adjacency matrix (use 0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; 
            }
        }
    }

    
    visited[1] = 1;
    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        min = 999;
        
        
        for (i = 1; i <= n; i++) {
            if (visited[i] != 0) { 
                for (j = 1; j <= n; j++) {
                    
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

       
        if (visited[u] == 1 && visited[v] == 0) {
            printf("Edge %d: (%d -> %d) cost: %d\n", ne++, a, b, min);
            mincost += min;
            visited[v] = 1; 
        }

        
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

