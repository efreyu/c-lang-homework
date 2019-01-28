/*
 * Created by efreyu on 1/28/19.
 *
 * Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной
 * и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
 */

#include <stdio.h>

void bubble_sort(int list[], int len, int * count);

int main(int argc, const char *argv[]) {
    int array[100], len, i, counter = 0;

    printf("Введите количество элементов массива\n");
    scanf("%d", &len);

    printf("Вы указали %d, теперь введите его значения\n", len);

    for (i = 0; i < len; i++)
        scanf("%d", &array[i]);

    bubble_sort(array, len, &counter);

    printf("Отсортированный массив содержит:\n");

    for (i = 0; i < len; i++)
        printf("%d\n", array[i]);

    printf("Было выполненно %d операций(операции)\n", counter);

    return 0;
}

void bubble_sort(int list[], int len, int * count) {
    int i, j, temp;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                *count = *count + 1;
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}