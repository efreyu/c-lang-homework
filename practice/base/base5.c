/*
 * Created by efreyu on 1/24/19.
 * Выводим числа Армстронга в заданном диапазоне
 * Output Armstrong numbers in a given range
 *
 * see practice/base/base4.c
 */
#include <stdio.h>

int main(int argc, const char *argv[]) {
    int low, high, temp1, temp2, remainder, n = 0, result = 0;

    printf("Enter your two numbers: ");
    scanf("%d %d", &low, &high);

    for (int i = low + 1; i < high; ++i) {
        temp1 = i;
        temp2 = i;

        //see practice/base/base4.c
        while (temp1 != 0) {
            temp1 /= 10;
            ++n;
        }

        while (temp2 != 0) {
            remainder = temp2 % 10;
            result += pow(remainder, n);
            temp2 /= 10;
        }

        //checking, number is Armstrong number
        if (result == i) {
            printf("%d ", i);
        }

        //clear temp for new iteration
        n = 0;
        result = 0;
    }

    printf("\n");

    return 0;
}