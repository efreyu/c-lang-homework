/*
 * Created by efreyu on 1/25/19.
 * Конвертация десятичных чисел в двоичные и наоборот
 * Convert decimal to binary and binary to decimal
 *
 * test case: enter first 10001, then 17
 */
#include <stdio.h>

int convertDecimalToOctal(int decimalNumber);

long long convertOctalToDecimal(int octalNumber);

int main(int argc, const char *argv[]) {

    int decimalNumber, octalNumber;
    printf("Enter your decimal number");
    scanf("%d", &decimalNumber);
    printf("%d is your decimal number and it is equivalent to octal %d\n", decimalNumber,
           convertDecimalToOctal(decimalNumber));

    printf("Enter your octal number");
    scanf("%d", &octalNumber);
    printf("%d is your octal number and it is equivalent to decimal %lld\n", octalNumber,
           convertOctalToDecimal(octalNumber));

    return 0;
}

int convertDecimalToOctal(int decimalNumber) {
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}

long long convertOctalToDecimal(int octalNumber) {
    int decimalNumber = 0, i = 0;

    while (octalNumber != 0) {
        decimalNumber += (octalNumber % 10) * pow(8, i);
        ++i;
        octalNumber /= 10;
    }
    i = 1;

    return decimalNumber;
}
