/*
 * Created by efreyu on 1/24/19.
 *
 * Реализовать функцию возведения числа 'a' в степень 'b'
 */
#include <stdio.h>

#define true 1
#define false 0

int power(int n1, int n2);

int main(int argc, const char *argv[]) {

    int a, powerInt, result;

    printf("Введите первое число: ");
    scanf("%d", &a);

    printf("Введите второе число для возведения в степень: ");
    scanf("%d", &powerInt);

    result = power(a, powerInt);
    printf("%d в степени %d = %d", a, powerInt, result);

    return 0;
}

int power(int a, int powerInt) {
    if (powerInt != false) {
        return (a * power(a, powerInt - 1));
    }

    return 1;
}