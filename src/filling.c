#include <stdlib.h>
#include "filling.h"

int ***createFilled(int *value, int size) {

    int ***mat = (int***)malloc(size * sizeof(int**));
    
    for (int i = 0; i < size; i++){
        mat[i] = (int**)calloc(size, sizeof(int*));
    }

    // Filling
    int x = 0;
    int y = 0;
    int i = 0;
    while (1 == 1) {
        mat[y][x] = &value[i++];
        if (x - 1 >= 0 && mat[y][x - 1] == NULL && (y - 1 < 0 || mat[y - 1][x] != NULL)) {
            x -= 1;
        } else if (y + 1 < size && mat[y + 1][x] == NULL) {
            y += 1;
        } else if (x + 1 < size && mat[y][x+1] == NULL) {
            x += 1;
        } else if (y - 1 >= 0 && mat[y - 1][x] == NULL) {
            y -= 1;
        } else break;
    }

    return mat;
}
