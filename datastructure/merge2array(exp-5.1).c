#include <stdio.h>

int main() 
{
    int a[50], b[50], c[100], m, n, j, k, i; 
    printf("\nEnter the size of the first array: ");
    scanf("%d", &m);
    printf("Enter the elements of first array (must be sorted): ");
    for (i = 0; i < m; i++) {   
        scanf("%d", &a[i]);
    }

    printf("\nEnter the size of the second array: ");
    scanf("%d", &n);
    printf("Enter the elements of second array (must be sorted): ");
    for (i = 0; i < n; i++) {   
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {    
            c[k] = b[j];
            j++;
        }
        k++;
    }

    
    while (i < m) {
        c[k] = a[i];
        i++;
        k++;
    }

    
    while (j < n) {
        c[k] = b[j];
        j++;
        k++;
    }

    
    printf("\nMerged sorted array = ");
    for (i = 0; i < m + n; i++) {
        printf("%d ", c[i]); 
    }
    printf("\n");

    return 0;
}

