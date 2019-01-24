/*
 * Created by efreyu on 1/24/19.
 *
 * Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
 */
#include <stdio.h>
#define true 1
#define false 0

int convertToBinary(int a);

int main(int argc, const char *argv[]) {

    int decimal, binary;

    printf("Введите десятичное число: ");
    scanf("%d", &decimal);

    binary = convertToBinary(decimal);
    printf("Вы ввели %d, оно эквивалентно %d.\n", decimal, binary);

    return 0;
}

int convertToBinary(int decimal) {

    if (decimal != false) {
        return (decimal % 2 + 10 * convertToBinary(decimal / 2));
    }

    return 0;
}
