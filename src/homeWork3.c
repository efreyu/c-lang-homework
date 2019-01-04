/*
 * Created by efreyu on 04.01.19.
 */
#include <stdio.h>

int main(int argc, const char* argv[]) {
    int input, loop = 1;
    do {
        printf("Введите номер задания:(1/2/3/4) 0 для выхода\n");
        scanf("%d", &input);
        switch (input) {
            case 0:
                printf("Спасибо за просмотр!\n");
                loop = 0;
                break;
            case 1:
//                task1();
                break;
            default:
                printf("Вы ввели недопустимый символ.\n");
                break;
        }
    } while (loop);

    return 0;
}