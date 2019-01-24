/*
 * Created by efreyu on 1/24/19.
 *
 */
#include <stdio.h>

#define true 1
#define false 0

int F(int n);

int G(int n);

int main(int argc, const char *argv[]) {

    printf("G(6) = %d\n", G(6));

    return 0;
}

int F(int n) {
    if (n > 2) {
        return F(n - 1) + G(n - 2);
    }
    return n;
}

int G(int n) {
    if (n > 2) {
        return G(n - 1) + F(n - 2);
    }
    return 3 - n;
}