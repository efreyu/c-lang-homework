/*
 * Created by efreyu on 1/25/19.
 *
 * Конвертация двоичных чисел в восмеричные и наоборот
 * Convert numbers: binary to octal and octal to binary
 *
 * test case: enter first 10001
 */
#include <stdio.h>

long long convertOctalToBinary(int octalNumbers);
int convertBinaryToOctal(long long binaryNumbers);
int main(int argc, const char *argv[]) {

    long long binaryNumber;
    int octalNumber;

    printf("Enter your binary number: ");
    scanf("%lld", &binaryNumber);

    printf("%lld is your binary number and it is equivalent to octal %d\n", binaryNumber, convertBinaryToOctal(binaryNumber));

    printf("Enter your octal number: ");
    scanf("%d", &octalNumber);

    printf("%d is your octal number and it is equivalent to binary %lld\n", octalNumber, convertOctalToBinary(octalNumber));

    return 0;
}

long long convertOctalToBinary(int octalNumbers) {
    int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;

    while (octalNumbers != 0) {
        decimalNumber += (octalNumbers % 10) * pow(8, i);
        ++i;
        octalNumbers /= 10;
    }

    i = 1;

    while (decimalNumber != 0) {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }

    return binaryNumber;
}

int convertBinaryToOctal(long long binaryNumbers) {
    int octalNumber = 0,
            decimalNumber = 0,
            i = 0;

    while (binaryNumbers != 0) {
        decimalNumber += (binaryNumbers % 10) * pow(2, i);
        ++i;
        binaryNumbers /= 10;
    }

    i = 1;

    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}