/*
 * Created by efreyu on 1/24/19.
 * Проверяем сколько байт содержат разные типы данных.
 * Checking how many bytes contain data types.
 */
#include <stdio.h>


int main(int argc, const char *argv[]) {
    int integerType;
    float floatType;
    double doubleType;
    char charType;

    printf("Size of integer type - %ld bytes\n", sizeof(integerType));// 4 bytes
    printf("Size of float type - %ld bytes\n", sizeof(floatType));// 4 bytes
    printf("Size of double type - %ld bytes\n", sizeof(doubleType));// 8 bytes
    printf("Size of char type - %ld bytes\n", sizeof(charType));// 1 bytes

    printf("-------------------------------------------------------------\n");

    int a;
    long int g;

    long b;
    long long c;

    double e;
    long double f;

    printf("Size of integer type - %ld bytes\n", sizeof(a));// 4 bytes
    printf("Size of long integer type - %ld bytes\n", sizeof(g));// 8 bytes
    printf("Size of long type - %ld bytes\n", sizeof(b));// 8 bytes
    printf("Size of long long type - %ld bytes\n", sizeof(c));// 8 bytes
    printf("Size of double type - %ld bytes\n", sizeof(e));// 8 bytes
    printf("Size of long double type - %ld bytes\n", sizeof(f));// 16 bytes
    return 0;
}