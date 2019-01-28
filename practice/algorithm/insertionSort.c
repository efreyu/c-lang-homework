/*
 * Created by efreyu on 1/27/19.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

struct node *head = NULL;

void insert_node(int value);

int main(int argc, const char *argv[]) {
    struct node *current = NULL;
    struct node *next = NULL;
    int test[] = {8, 3, 2, 7, 4, 5, 1, 6, 0, 9};
    int i = 0;

    for (i = 0; i < 10; i++) {
        insert_node(test[i]);
    }

    printf("Before|After\n");
    i = 0;

    while (head->next != NULL) {
        printf("%4d  |%4d\n", test[i++], head->number);
        head = head->next;
    }

    for (current = head; current != NULL; current = next) {
        next = current->next, free(current);
    }
}

void insert_node(int value) {
    struct node *temp = NULL;
    struct node *one = NULL;
    struct node *two = NULL;

    if (head == NULL) {
        head = (struct node *) malloc(sizeof(struct node *));
        head->next = NULL;
    }

    one = head;
    two = head->next;

    temp = (struct node *) malloc(sizeof(struct node *));
    temp->number = value;

    while (two != NULL && temp->number < two->number) {
        one = one->next;
        two = two->next;
    }

    one->next = temp;
    temp->next = two;
}