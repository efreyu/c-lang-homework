/*
 * Created by efreyu on 1/28/19.
 *
 * Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
 * Функция возвращает индекс найденного элемента или -1, если элемент не найден.
 * Binary search
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int binarySearch(int arr[], int search);

int main(int argc, const char *argv[]) {
    int arr[MAX_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int number, result;

    printf("Ваш массив ");
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("[%d] ", arr[i]);
    }
    puts("");
    printf("Введите элемент индекс которого нужно найти: ");
    scanf("%d", &number);

    result = binarySearch(arr, number);
    if (result == -1) {
        printf("Ничего не найдено\n");
    } else {
        printf("Найдено по индексу - %d\n", result);
    }

    return 0;
}

int binarySearch(int arr[], int search) {
    int left = 0;
    int right = MAX_SIZE;
    int middle = 0;
    int result = -1;

    while (result == -1 && left <= right) {

        if (arr[middle] < search) {
            left = middle + 1;
        } else if (arr[middle] == search) {
            result = middle + 1;
        } else {
            right = middle - 1;
        }

        middle = (left + right) / 2;
    }

    return result;
}
