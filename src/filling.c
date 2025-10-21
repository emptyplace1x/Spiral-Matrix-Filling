#include <stdlib.h>
#include "filling.h"

int **createFilled(int *value, int size) {

    int **mat = (int**)malloc(size * sizeof(int*));
    
    for (int i = 0; i < size; i++){
        mat[i] = (int*)calloc(size, sizeof(int));
    }

    int numeration[size*size];
    for (int i = 0; i < size * size; i++) {
        numeration[i] = i + 1;
    }
    
    // Filling
    int x = 0;
    int y = 0;
    int i = 0;
    while (1 == 1) {
        mat[y][x] = numeration[i++];
        if (x - 1 >= 0 && mat[y][x - 1] == 0 && (y - 1 < 0 || mat[y - 1][x] != 0)) {
            x -= 1;
        } else if (y + 1 < size && mat[y + 1][x] == 0) {
            y += 1;
        } else if (x + 1 < size && mat[y][x+1] == 0) {
            x += 1;
        } else if (y - 1 >= 0 && mat[y - 1][x] == 0) {
            y -= 1;
        } else break;
    }

    for (i = 0; i < size; i++){
        for (int k = 0; k < size; k++){
            mat[i][k] = value[mat[i][k] - 1];
        }
    }

    return mat;
}
