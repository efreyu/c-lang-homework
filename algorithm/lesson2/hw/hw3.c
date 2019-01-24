/*
 * Created by efreyu on 1/24/19.
 *
 * Программа преобразует целое число. У программы две команды:
 *      Прибавь 1
 *      Умножь на 2
 * Сколько существует путей для данной программы, которые число 3 преобразуют в число 20?
 */
#include <stdio.h>

#define true 1
#define false 0

int convert(int n1, int n2);

int main(int argc, const char *argv[]) {

    int a, b, loop;
    printf("Введите число: ");
    scanf("%d", &a);
    loop = true;
    do {
        printf("Введите действие, прибавить 1(1)/умножить на 2(2), выйти(0): ");
        scanf("%d", &b);
        if (b == 1 || b == 2) {
            a = convert(a, b);
            printf("%s, результат %d\n", (b == 1 ? "Вы прибавили 1" : "Вы умножили на 2"), a);
        } else if (b == false) {
            printf("Выход, спасибо за просмотр!\n");
            loop = false;
        } else {
            printf("Вы ввели недопустимый символ\n");
        }
    } while (loop);

    return 0;
}

int convert(int a, int b) {
    if (b == 1) {
        return a + 1;
    }
    return a * 2;
}