/*
 * Created by efreyu on 1/24/19.
 * Вычисление факториала
 * Factorial calculation
 */
#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    unsigned long long factorial = 1;

    printf("Enter your number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Number cannot be less than zero or zero\n");
    } else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("The factorial of %d is %llu\n", n, factorial);
    }

    return 0;
}