#include <stdio.h>
#include <stdlib.h>

void print_and_free(int **mat, int size) {
    printf("Filled matrix is: \n\n");
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            printf("%d\t", mat[i][k]);
        }
        free(mat[i]);
        printf("\n");
    }
    free(mat);
}
