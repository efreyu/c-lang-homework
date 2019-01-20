/*
 * Created by efreyu on 04.01.19.
 *
 * 1. Строки.
 * Описать функцию, возвращающую строку с двоичным представлением десятичного числа, переданного
 * в аргументе этой функции.
 *
 * 2. Структуры.
 * Описать структуру «прямоугольник», содержащую целочисленные значения длины, ширины, периметра
 * и площади прямоугольника. Написать функцию, принимающую на вход указатель на структуру,
 * подсчитывающую и записывающую площадь и периметр данного прямоугольника в структуру.
 *
 * 3. Выделение памяти.
 * Написать функцию-обёртку, возвращающую указатель на область памяти, которую затем можно
 * использовать как массив из элементов типа integer. Количество элементов указывается в аргументе
 * функции. Массив должен быть гарантированно инициализирован нулями. Для проверки заполните этот
 * массив и выведите на экран.
 *
 * 4. *Описать структуру «прямая линия», которая должна состоять из длины и двух внутренних структур
 * типа «точка», в каждой из которых должны содержаться координаты по осям 'х' и 'у'. Описать функцию,
 * принимающую на вход координаты двух точек и возвращающую структуру «линия» с подсчитанной длиной.
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//альтернаивный синтаксис
//struct rectangle{
//    int height;
//    int width;
//    int perimetr;
//    int area;
//};
//typedef struct rectangle Rectangle;

typedef struct coord {
    float x;
    float y;
} Coord;

typedef struct point {
    int x;
    int y;
} Point;

typedef struct line {
    float length;
    Point point1;
    Point point2;
} Line;

typedef struct rectangle {
    int height;
    int width;
    int perimetr;
    int area;
} Rectangle;

void convertDoub(int number, char *out) {
    char result[256];
    int i = 0, trash = number;

    for (i = 0; trash != 0; ++i) {
        trash = trash >> 1;
    }
    result[i] = '\0';
    while (number > 0) {
        result[--i] = (number % 2) ? '1' : '0';
        number = number / 2;
    }

    strcat(out, result);
}

void task1() {
    char bin[256] = "";
    int number;

    printf("Введите число для конвертации:");
    scanf("%d", &number);
    convertDoub(number, bin);
    printf("Ваша строка: %s\n", bin);
}

void calcRec(Rectangle *rectangle) {
    rectangle->perimetr = (rectangle->height + rectangle->width) * 2;
    rectangle->area = rectangle->height * rectangle->width;
}

void task2() {
    Rectangle rectangle;
    printf("Введите высоту пряоугольника: ");
    scanf("%d", &rectangle.height);
    printf("Введите ширину пряоугольника: ");
    scanf("%d", &rectangle.width);

    calcRec(&rectangle);
    printf("Периметр пряоугольника: %d\n", rectangle.perimetr);
    printf("Площадь пряоугольника: %d\n", rectangle.area);
}

int* setArray(int l) {
    int sizeInt = sizeof(int);
    return calloc(l, sizeInt);
}

void task3() {
    const int SIZE = 5;
    int * arr = setArray(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        *(arr + i) = i * 10;
    }
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", *(arr + i));
    }
    puts("");
}

Line setLine(Coord * line1, Coord * line2) {
    Line result;
    result.point1.x = line1->x;
    result.point1.y = line1->y;
    result.point2.x = line2->x;
    result.point2.y = line2->y;
    result.length = sqrt(pow(result.point2.x - result.point1.x, 2) + pow(result.point2.y - result.point1.y, 2));

    return result;
}

void task4() {
    Coord coord1, coord2;
    coord1.x = 2;
    coord1.y = 8;
    coord2.x = 4;
    coord2.y = 5;
    Line line = setLine(&coord1, &coord2);
    printf("Точка #1 имеет координаты x = %d, y = %d\n", line.point1.x, line.point1.y);
    printf("Точка #2 имеет координаты x = %d, y = %d\n", line.point2.x, line.point2.y);
    printf("Линия имеет длинну %f\n", line.length);
}

int main(int argc, const char *argv[]) {
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