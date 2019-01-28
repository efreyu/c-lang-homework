/*
 * Created by efreyu on 1/28/19.
 *
 * Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной
 * и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
 */

#include <stdio.h>

int bubble_sort_one(int arr[], int len);

int bubble_sort_two(int arr[], int len);

int main(int argc, const char *argv[]) {
    int len = 10, i;
    int array1[100] = {9,8,7,6,5,4,3,2,1,0};
    int array2[100] = {9,8,7,6,5,4,3,2,1,0};


    printf("В bubble_sort_one было выполненно %d операций(операции)\n", bubble_sort_one(array1, len));
    printf("В bubble_sort_two было выполненно %d операций(операции)\n", bubble_sort_two(array2, len));

    return 0;
}

int bubble_sort_one(int arr[], int len) {
    int i, j, temp, count = 0;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                count = count + 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return count;
}

int bubble_sort_two(int arr[], int len) {
    int i, j, temp, count = 0;

    for (i = len - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j + 1] < arr[j]) {
                count = count + 1;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return count;
}