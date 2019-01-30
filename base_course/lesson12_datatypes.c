//
// Created by efreyu on 1/20/19.
//
#include <stdio.h>

struct fraction {
    int integer;
    int divisile;
    int divisor;
};
typedef struct fraction Fraction;

void printFraction (Fraction frac) {
    if (frac.divisile != 0) {
        if (frac.integer == 0) {
            printf("%d / %d\n", frac.divisile, frac.divisor);
        } else {
            printf("%d %d/%d\n", frac.integer, frac.divisile, frac.divisor);
        }
    } else {
        printf("%d\n", frac.integer);
    }
}

void fractionMultiply(Fraction f1, Fraction f2, Fraction * result) {
    result->divisile = f1.divisile * f2.divisile;
    result->divisor = f1.divisor * f2.divisor;
    result->integer = f1.integer * f2.integer;
}

int main(int argc, const char *argv[]) {
    Fraction f1, f2, result;
    f1.integer = -1;
    f2.integer = 1;
    f1.divisile = 3;
    f2.divisile = 6;
    f1.divisor = 2;
    f2.divisor = 8;
    printf("test\n");
    puts("");
    printFraction(f1);
    printFraction(f2);
    fractionMultiply(f1, f2, &result);
    printFraction(result);

    return 0;
}
