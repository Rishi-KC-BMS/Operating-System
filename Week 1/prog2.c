#include <stdio.h>

int main() {
    int n, i, j, sum = 0;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    printf("Sum of left diagonal: %d\n", sum);
    return 0;
}
// Enter order of matrix: 3
// Enter matrix elements:
// 1 0 1 
// 2 3 1
// 1 0 6
// Sum of left diagonal: 10