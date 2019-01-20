/*
 * Created by efreyu on 31.12.18.
 * Для практики обернул всё в функции task1 task2...
 * И сделал выбор задания в консоли
 *
 * 1. Математика.
 * Есть формула (расчёта резисторного делителя) Uo = Ui * (R1 / (R2 + R1)).
 * Напишите формулы расчёта каждой переменной по отдельности, в формате:
 * Ui = ...;
 * R1 = ...;
 * R2 = ...;
 *
 * 2. Условия.
 * Запросить у пользователя любое целое число. Написать программу, которая проверит,
 * входит ли введённое число в диапазон (например, от 0 до 100 включительно) и
 * выведет на экран сообщение о результате проверки.
 *
 * 3. Циклы, часть 1
 * Запросить у пользователя десять чисел. Вывести на экран среднее арифметическое
 * введённых чисел.
 *
 * 4. Циклы, часть 2
 * Запросить у пользователя количество используемых для вывода строк. Написать
 * программу, которая при помощи циклов и символа ^ будет рисовать на указанном
 * количестве строк равнобедренный треугольник.
 */
#include <stdio.h>

int task1();
int task2();
int task3();
int task4();

int main(int argc, const char* argv[]) {
    int input, loop = 1;
    do {
        printf("Введите номер задания:(1/2/3/4) 0 для выхода\n");
        scanf("%d", &input);
        switch (input) {
            case 0:
                printf("Спасибо за просмотр!\n");
                loop = 0;
                break;
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            default:
                printf("Вы ввели недопустимый символ.\n");
                break;
        }
    } while (loop);

    return 0;
}

int task1() {

    printf("Формулы расчёта каждой переменной\n");
    const char *string = {
            "Uo = Ui * (R1 / (R2 + R1))\n"
            "Ui = Uo * (R1 + R2) / R1\n"
            "R1 = R2 * Uo / (Ui - Uo)\n"
            "R2 = (Ui - Uo) * R1 / Uo\n"
    };
    puts(string);

}

int task2() {

    const int MIN_NUMBER = 0;
    const int MAX_NUMBER = 100;
    int input;
    printf("Проверка, входит ли введённое число в диапазон от %d до %d.\n",
            MIN_NUMBER,
            MAX_NUMBER
            );
    printf("Введите число: ");
    scanf("%d", &input);
    printf("Число %d %s в диапозон от %d до %d.\n",
            input,
            (input >= MIN_NUMBER && input <= MAX_NUMBER) ? "входит" : "не входит",
            MIN_NUMBER,
            MAX_NUMBER
            );

}

int task3() {

    const int NUMBERS_COUNT = 10;
    printf("Вывод на экран среднее арифметическое введённых %d чисел\n", NUMBERS_COUNT);
    float summ = 0;
    int input, i = 0;
    do {
        printf("Введите число: ");
        scanf("%d", &input);
        summ += input;
    } while (++i < NUMBERS_COUNT);

    printf("Среднее арифметическое %d введённых чисел: %.2f\n", NUMBERS_COUNT, summ / NUMBERS_COUNT);

}

int task4() {
    // Ограничение вывода
    const int MIN_ROWS = 3;
    const int MAX_ROWS = 30;
    printf("Вывод н экран равнобедренного треугольника.\n");
    printf("Введите число строк: ");
    int rows;
    scanf("%d", &rows);
    rows = (rows >= MIN_ROWS && rows <= MAX_ROWS) ? rows : MAX_ROWS;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i; ++j) {
            printf(" ");
        }
        for (int j = rows - i * 2; j <= rows; ++j) {
            printf("^");
        }
        printf("\n");
    }

}