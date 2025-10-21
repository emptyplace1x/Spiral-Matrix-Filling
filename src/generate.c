#include "generate.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int* generate(int size) {
    switch (chooseMode()) {
        int val1;
        int val2;
        case '1':
            printf("Enter start value: "); scanf("%d", &val1);
            printf("Enter step value: "); scanf("%d", &val2);
            return generateIncreative(val1, val2, size);
            break;
        case '2':
            printf("Enter min value: "); scanf("%d", &val1);
            printf("Enter max value: "); scanf("%d", &val2);
            return generateRandom(val1, val2, size);
            break;
        case '3':
            return inputManually(size);
            break;
        default:
            printf("Unexisting mode.");
            return NULL;
    }
}

int chooseMode() {
    printf("Choose mode of generating vector:\n");
    printf("\t1) For generating increative\n");
    printf("\t2) For generating random\n");
    printf("\t3) For manual generating\n");

    while (getchar() != '\n');
    int mode = getchar();
    return mode;
}

int* generateIncreative(int start, int step, int size){
    int* vector = malloc(size * sizeof(int));

    printf("Generated vector is { ");
    for (int i = 0; i < size; i++ ) {
        vector[i] = start;
        start += step;
        printf("%i ", vector[i]);
    }
    printf("}\n");

    return vector;
}

int* generateRandom(int min, int max, int size) {
    int* vector = malloc(size * sizeof(int));

    srand(time(NULL));
    printf("Generated vector is { ");
    for (int i = 0; i < size; i++ ) {
        vector[i] = rand() % (max - min) + min;
        printf("%i ", vector[i]);
    }
    printf("}\n");

    return vector;
}

int* inputManually(int size) {
    int* vector = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter vector element %d: ", i); scanf("%d", &vector[i]);
    }
    
    return vector;
}







