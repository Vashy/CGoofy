#include <stdio.h>
#include <stdlib.h>

#include "headers/list.h"

void printArr(void*, size_t);

int main(int argc, char const *argv[]) {

    List l1 = new_list_from_int(-11);
    List l2 = new_list_from_int(5);

    for (int i = 0; i < 10; i++) {
        (i % 2 == 0)
            ? push_front_int(&l2, i*10)
            : push_back_int(&l2, i*10);
    }

    push_back_int(&l1, 7);
    push_back_int(&l1, 12);
    // fprint_list_int(stdout, l2);
    // fprint_list_int_backward(stdout, l2);

    pop_front(&l2);
    pop_back(&l2);

    printf("l1: ");
    fprint_list_int(stdout, l1);

    printf("l12: ");
    fprint_list_int(stdout, l2);

    int value = 30;
    int steps = contains_int(&l2, value);
    if (steps) {
        printf("\nl2 contains %d\n", value);
        printf("Number of steps: %d\n", steps);
    }

    printf("\nPre join:\n");
    printf("l1: ");
    fprint_list_int(stdout, l1);
    printf("l2: ");
    fprint_list_int(stdout, l2);

    join_lists(&l1, &l2);

    printf("\nPost join:\n");
    printf("l1: ");
    fprint_list_int(stdout, l1);
    printf("l2: ");
    fprint_list_int(stdout, l2);

    Node* node1 = fetch_int(&l1, 7);
    Node* node2 = fetch_int(&l1, 12321);
    printf("\nFound Node containing %d\n", *(int*)node1->data);
    if (node2 == NULL)
        printf("Not found a Node containinig 12321: %p\n", node2);

    destroy_list(&l2);
}

void printArr(void* arr, size_t size) {
    int* res = arr;
    for (size_t i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}
