//
// Created by efreyu on 1/20/19.
//
#include <stdio.h>

int main(int argc, const char *argv[]) {
    FILE *f;
    f = fopen("filename.txt", "w"); // r - read, w - write, a - append, rb, wb, ab
    if (f == NULL) {
        return 1;
    }
    fprintf(f, "Hello! %s", "We did it! \n");
    fclose(f);

    char word[256];
    f = fopen("filename.txt", "r"); // r - read, w - write, a - append, rb, wb, ab
    if (f == NULL) {
        return 1;
    }
    while (!feof(f)) {
        fscanf(f, "%s ", &word);
        printf("%s ", word);
    }
    fclose(f);

    return 0;
}
