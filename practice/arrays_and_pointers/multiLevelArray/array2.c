/*
 * Created by efreyu on 2/3/19.
 *
 * Use a (dynamically allocated) array of pointers to (dynamically allocated) arrays.
 * This is used mostly when the array bounds are not known until runtime.
 */
#include <stdio.h>
#include <stdlib.h>

void fillArray(int rows, int cols, int **array) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            array[i][j] = i * j;
        }
    }
}

void dump(int rows, int cols, int **array) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        printf("%d => [", i);
        for (j = 0; j < cols; ++j) {
            array[i][j] = i * j;
            printf("    [%d:%d] ", j, array[i][j]);
        }
        printf("]\n");
    }
}

int main(int argc, const char *argv[]) {
    int rows = 5, cols = 10, i;
    int **array;

    /*obtain values for rows & cols*/

    /*allocate the array*/
    array = malloc(rows * sizeof *array);
    for (i = 0; i < rows; ++i) {
        array[i] = malloc(cols * sizeof *array[i]);
    }
    fillArray(rows, cols, array);
    dump(rows, cols, array);

    /*deallocate the array*/
    for (i = 0; i < rows; ++i) {
        free(array[i]);
    }
    free(array);

    return 0;
}