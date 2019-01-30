//
// Created by efreyu on 1/20/19.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    const int SIZE = 10;
//    void* malloc(<memory size>);

    int variable;
    int memorySize = sizeof(int) * SIZE;
//    int * area = (int*) malloc(sizeof(int) * SIZE);
    int * area = (int*) calloc(SIZE, sizeof(int));
    //почти идентично
    int a[10];

    for (int i = 0; i < SIZE; ++i) a[i] = i * 10;
    for (int i = 0; i < SIZE; ++i) printf("%d ", a[i]);
    puts("");
    /*for (int i = 0; i < SIZE; ++i) area[i] = i * 10;
    for (int i = 0; i < SIZE; ++i) printf("%d ", area[i]);*/
    for (int i = 0; i < SIZE; ++i) *(area + i) = i * 10;
    for (int i = 0; i < SIZE; ++i) printf("%d ", *(area + i));

    puts("");
//    free(area);
    int newSize = SIZE * 10;
    area = realloc(area, sizeof(int) * newSize);
    for (int i = 0; i < newSize; ++i) *(area + i) = i * 10;
    for (int i = 0; i < newSize; ++i) printf("%d ", *(area + i));
    return 0;
}