/*
 * Created by efreyu on 1/24/19.
 * Является ли год високосным?
 * Is the year a leap year?
 */
#include <stdio.h>

int yearIsLeap(int *year);

int main(int argc, const char *argv[]) {

    int year;

    printf("Enter year:");
    scanf("%d", &year);

    if (yearIsLeap(&year) == 0) {
        printf("%d - is not a leap year\n", year);
    } else {
        printf("%d - is a leap year\n", year);
    }

    return 0;
}

/// @param year
/// @return int
/// 0 - year is leap
/// 1 - year is not leap
int yearIsLeap(int *year) {
    if (*year % 4 == 0) {
        if (*year % 100 == 0) {
            // if the year is divisible by 400 then it means it is a leap year
            if (*year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    }

    return 0;
}