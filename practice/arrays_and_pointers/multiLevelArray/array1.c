/*
 * Created by efreyu on 2/3/19.
 *
 * Use an array of arrays. This can only be used if your array bounds
 * are fully determined at compile time, or if your compiler supports VLA's
 */
#include <stdio.h>

#define ROWS 5
#define COLS 10

void func(int array[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            array[i][j] = i * j;
        }
    }
}

void func_vla(int rows, int cols, int array[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            array[i][j] = i * j;
        }
    }
}

int main(int argc, const char *argv[]) {
    int array[ROWS][COLS];

//    func(array);
    func_vla(ROWS, COLS, array);

    return 0;
}