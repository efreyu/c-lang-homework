/*
 * Created by efreyu on 04.01.19.
 *
 * 1. Указатели.
 * Используя заголовочный файл <math.h>, описать функцию
 * int calculateSquareEquality(int a, int b, int c, float* x1, float* x2),
 * которая будет решать квадратное уравнение вида a * x ^ 2 + b * x + c = 0,
 * и записывать корни этого уравнения в переменные, адреса которых переданы
 * в качестве указателей х1 и х2. Функция должна вернуть -1, если уравнение
 * не имеет корней, 0, если у уравнения есть один корень, и 1, если у уравнения два корня.
 *
 * 2. Массивы, часть 1.
 * Инициализировать массив из целых чисел, описать функцию, принимающую
 * на вход этот массив. Функция должна вернуть ноль, если в массиве нет
 * нечётных чисел, в противном случае удвоить все нечётные числа в массиве
 * и вернуть единицу. После выполнения функции, если массив был изменён,
 * вывести все числа из него на экран.
 *
 * 3. Массивы, часть 2.
 * Как известно, переменная типа integer занимает в памяти 4 байта, а
 * переменная типа short — два байта. Опишите функцию, которая принимает
 * массив из тридцатидвухразрядных чисел (типа int), и выводит его на
 * экран шестнадцатиразрядными числами (типа short). По сути, это задача
 * приведения типа массива. Широко применяется для расшифровывания данных
 * из входящих потоков или логов цифровых систем.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_LENGTH 15
#define boolean int
#define true 1
#define false 0

int calculateSquareEquality(int a, int b, int c, float* x1, float* x2);
int arrayChanged(int *arr, int count);
int randint(int n);
void convertToShort(unsigned int* array, int length);
void task1();
void task2();
void task3();

int main(int argc, const char* argv[]) {

    int input, loop = 1;
    do {
        printf("Enter task number: (1/2/3) 0 to exit\n");
        scanf("%d", &input);
        switch (input) {
            case 0:
                printf("Thank you for watching!\n");
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
            default:
                printf("You entered an invalid character.\n");
                break;
        }
    } while (loop);

    return 0;
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

int arrayChanged(int* arr, int count) {

    boolean isNonOdd = false;
    for (int i = 0; i < count; ++i) {
//        arr[i] = arr[i] *2; printf("check %d\n", arr[i] % 2); // for debug
        if (arr[i] % 2 != 0) {
            isNonOdd = true;
            // Удваиваем нечётные
            arr[i] = arr[i] *2;
        }
    }
    /*if (isNonOdd) {
        for (int i = 0; i < count; ++i) {
            arr[i] = arr[i] *2;
        }
    }*/
    return isNonOdd;
}

/*
 * Returns an integer in the range (0, n)
 */
int randint(int n) {

    if ((n - 1) == RAND_MAX) {
        return rand();
    } else {
        assert (n <= RAND_MAX);

        int end = RAND_MAX / n;
        assert (end > 0);
        end *= n;

        int r;
        while ((r = rand()) >= end);

        return r % n;
    }

}

void task1() {

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

void task2() {

    int userArrayLength;
    printf("Enter the length of the array (press 0 to choose default value: %d): \n", ARRAY_LENGTH);
    scanf("%d", &userArrayLength);
    int arrayLength = userArrayLength != 0 ? userArrayLength : ARRAY_LENGTH,
        array[arrayLength];
    //Наполняем массив
    printf("Original array contains [key:val]: ");
    for (int i = 0; i < arrayLength; ++i) {
//        array[i] = i + 1; // for debug - последовательные числа
        array[i] = randint(20);
        printf("[%d:%d]", i, array[i]);
    }
    printf("\n");
    //Если массив был изменён то вывести все числа массива
    if (arrayChanged(array, arrayLength)) {
        printf("Array has been changed, and contains [key:val]: ");
        for (int i = 0; i < arrayLength; ++i) {
            printf("[%d:%d]", i, array[i]);
        }
        printf("\n");
    } else {
        printf("Array is not changed.\n");
    }

}

void task3() {

    int userArrayLength;
    printf("Enter the length of the array (press 0 to choose default value: %d): \n", ARRAY_LENGTH);
    scanf("%d", &userArrayLength);
    int arrayLength = userArrayLength != 0 ? userArrayLength : ARRAY_LENGTH;
    unsigned int array[arrayLength];
    //Наполняем массив
    printf("Original array contains [key:val]: ");
    for (int i = 0; i < arrayLength; ++i) {
//        array[i] = i + 1; // for debug - последовательные числа
        array[i] = randint(4000000);
        printf("[%d:%d]", i, array[i]);
    }
    printf("\n");
    convertToShort(array, arrayLength);

}

void convertToShort(unsigned int* array, int length) {
    printf("Array has been changed, and contains [key:val]: ");
    for (int i = 0; i < length*2; ++i) {
        printf("[%d:%d]", i, (unsigned short)array[i]);
    }
    printf("\n");
}