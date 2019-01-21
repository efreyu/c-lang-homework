/*
 * Created by efreyu on 1/21/19.
 * 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в
 * килограммах, h - рост в метрах.
 * 2. Написать программу обмена значениями двух целочисленных переменных:
 * a. с использованием третьей переменной;
 * b. *без использования третьей переменной.
 * 3. Написать программу нахождения корней заданного квадратного уравнения.
 * 4. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
 * 5. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
 * 6. *С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить,
 * относятся ли к поля к одному цвету или нет.
 * 7. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления
 * нацело N на K, а также остаток от этого деления.
 * 8. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в
 * записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
 * 9. * Написать функцию, генерирующую случайное число от 1 до 100. без использования стандартной функции rand()
 * 10. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
 * Например, 25 \ :sup: 2 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все
 * автоморфные числа, не превосходящие N.
 * 11. В тексте программы, написанной на уроке избавиться от условия в цикле.
 */
#include <stdio.h>
#include <math.h>

typedef struct month
{
    char name[256];
} Month;

void task1();
void task2();
void changeTwoVar(int * p1, int * p2);
void task3();
int calculateSquareEquality(int a, int b, int c, float* x1, float* x2);
void task4();

int main(int argc, const char* argv[]) {
    int input, loop = 1;
    do {
        printf("Введите номер задания:(1/2...11) 0 для выхода\n");
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

void task1() {
    int m = 0, h;
    printf("Расчёт индекс массы тела по формуле I=m/(h*h)\n");
    while (m <= 0) {
        printf("Введите массу в килограммах (m) (любое положительное число): ");
        scanf("%d", &m);
    }
    printf("Введите рост в метрах (h) (любое положительное число): ");
    scanf("%d", &h);
    printf("Индекс массы тела = %.2f\n", m / pow(h, 2));

}

void task2() {
    int p1, p2;
    printf("Скрипт обмена двух целочисленных значений.\n");
    printf("Введите первое число: ");
    scanf("%d", &p1);
    printf("Введите второе число: ");
    scanf("%d", &p2);
    printf("Вы ввели %d %d\n", p1, p2);
    changeTwoVar(&p1, &p2);
    printf("Переменны после обмена значениями %d %d\n", p1, p2);
}

void changeTwoVar(int * p1, int * p2) {
//    int t;
//    t = *p2;
//    *p2 = *p1;
//    *p1 = t;
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
}

void task3() {
    int a, b, c;
    float x1, x2;
    printf("Enter a value for the variable 'a' ");
    scanf("%d", &a);
    printf("Enter a value for the variable 'b' ");
    scanf("%d", &b);
    printf("Enter a value for the variable 'c' ");
    scanf("%d", &c);

//    calculateSquareEquality(a, b, c, &x1, &x2);
    switch (calculateSquareEquality(a, b, c, &x1, &x2)) {
        case -1:
            printf("The equation has no square roots.\n");
            break;
        case 0:
            printf("The equation has one square root.\n");
            break;
        case 1:
            printf("The equation has two square roots.\n");
            break;
    }
}

int calculateSquareEquality(int a, int b, int c, float* x1, float* x2) {
    /*
     * Решение квадратных уравнений
     * a * x ^ 2 + b * x + c = 0
     * Вычисляем дискриминант
     */
    double squareRoots = pow(b, 2) - 4*a*c;
    printf("The discriminant is equal to: %.2f\n",squareRoots);

    //Если дискриминант больше или равен 0 то корни есть
    //Если нет то корней нет
    if(squareRoots > 0) {
        //Два корня
//        *x1 = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
        *x1 = (-b + sqrt(squareRoots)) / 2 * a;
        printf("The first square root is %.2f\n", x1);
//        *x2 = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        *x2 = (-b - sqrt(squareRoots)) / 2 * a;
        printf("The second square root is %.2f\n", x2);

        return 1;
    } else if (squareRoots == 0) {
        //Один корень
        *x1 = -b / (2 * a);
        printf("The one square root is %.2f\n", x1);
        return 0;
    }

    // Нет корней или (squareRoots < 0)
    // Таким образом функция возвращает -1, 0, либо 1
    return -1;
}

void monthInit(char* month, int length) {
    //
}

void task4() {
    const int MIN_SIZE = 0;
    const int MAX_SIZE = 12;
    int input = MIN_SIZE;
    char month[12][25] = {"January-winter", "February-winter", "March-spring", "April-spring", "May-spring", "June-summer",
                       "July-summer", "August-Summer", "September-autumn","October-autumn", "November-autumn", "December-winter"};

//    for (int i = 0; i < 12; ++i) {
//        printf("string = %s \t address = %u\n", month + i, month + i);
//    }
    while (input <= 0) {
        printf("Введите номер месяца для определения к какому времени года он относится: ");
        scanf("%d", &input);
        if (input > MIN_SIZE && input <= MAX_SIZE && month + (input - 1)) {
            printf("Ура, это %s\n", month + (input - 1));
//            puts(month + (input - 1));
        } else {
            printf("Вы ввели '%d', это не корректное число, повторите попытку.\n", input);
            input = -1;
        }
    }

}