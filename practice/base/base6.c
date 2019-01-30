/*
 * Created by efreyu on 1/24/19.
 * Вычисление факториала
 * Factorial calculation
 */
#include <stdio.h>

long int fact(int n);

int main(int argc, const char *argv[]) {

    int n;
    printf("Enter your number: ");
    scanf("%d", &n);
    if (n > 0) {
        printf("The factorial of %d is %ld\n", n, fact(n));
    } else {
        printf("Number cannot be less than zero or zero\n");
    }

    return 0;
}

long int fact(int n) {
    if (n >= 1) {
        return n * fact(n - 1);
    } else {
        return 1;
    }
}