#include <stdio.h>
#include <time.h>

#include "generate.h"
#include "filling.h"
#include "output.h"

int main() {
    int mat_size;
    printf("Set the matrix size: "); scanf("%d", &mat_size);

    int vector_size = mat_size * mat_size;

    int *vector = generate(vector_size);

    clock_t begin = clock();

    int ***mat = createFilled(vector, mat_size);
    // Output
    print_and_free(mat, mat_size);

    clock_t end = clock();

    double execution_time = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %lf\n", execution_time);

    return 0;
}
