/*
 * Created by efreyu on 04.01.19.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//isalpha() isdigit() isspace() isupper() islower() toupper() tolower()
void helloFunc(char *name, char *out) {
    char welcome[256] = "Hello, ";
    name[0] = tolower(name[0]);
    if (strcmp("ivan", name) == 0)
        strcpy(name, "Master!");
    name[0] = toupper(name[0]);
    strcat(welcome, name);
    strcpy(out, welcome);
}

int main(int argc, const char *argv[]) {
    char str1[256] = "This is a string.";
    char *str2 = "This is also a string.";

    printf("%s \n", str1);
    printf("%s \n", str2);

    str1[5] = 'X';
    printf("%s \n", str1);

    char name[256];
    char result[256];

    fgets(name, 255, stdin);

    helloFunc(name, result);

    puts(result);

    //atoi() atof()
    // convert to int/float
}
