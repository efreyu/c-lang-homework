/*
 * Created by efreyu on 1/25/19.
 * Конвертация десятичных чисел в двоичные и наоборот
 * Convert decimal to binary and binary to decimal
 *
 * test case: enter first 10001, then 17
 */
#include <stdio.h>
#define DEBUG_MODE 1

int convertBinaryToDecimal(long long n);

long long convertDecimalToBinary(int n);

int main(int argc, const char *argv[]) {

    long long n;
    printf("Enter your binary number");
    scanf("%lld", &n);
    printf("%lld is your binary number and it is equivalent to decimal %d\n", n, convertBinaryToDecimal(n));

    printf("Enter your decimal number");
    scanf("%d", &n);
    printf("%lld is your decimal number and it is equivalent to binary %lld\n", n, convertDecimalToBinary(n));

    return 0;
}

int convertBinaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

long long convertDecimalToBinary(int n) {
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0) {
        remainder = n % 2;
        if (DEBUG_MODE) {
            printf("Step %d: %d/2, Remainder: %d, Quotient: %d\n", step++, n, remainder, n / 2);
        }
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}