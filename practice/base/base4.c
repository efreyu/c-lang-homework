/*
 * Created by efreyu on 1/24/19.
 * Проверяем, является ли число числом Армстронга
 * Checking current number is Armstrong number
 * pluperfect digital invariant, PPDI
 */
#include <stdio.h>

int main(int argc, const char *argv[]) {
    int number, originalNumber, remainder, result = 0, n = 0;

    printf("Enter your number:");
    scanf("%d", &number);

    originalNumber = number;
    while (originalNumber != 0) {
        originalNumber /= 10;
        ++n;
    }
    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }

    if (result == number) {
        printf("%d - is Armstrong number.\n", number);
    } else {
        printf("%d - is not Armstrong number.\n", number);
    }

    return 0;
}