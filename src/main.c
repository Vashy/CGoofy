#include <stdio.h>
#include <stdlib.h>

#include "headers/list.h"

void printArr(void*, size_t);

int main(int argc, char const *argv[]) {

    List l2 = new_list_from_int(5);

    for (int i = 0; i < 10; i++) 
        push_front_int(&l2, i*10);

    fprint_list_int(stdout, l2);
    // fprint_list_int_backward(stdout, l2);

    pop_front(&l2);
    pop_back(&l2);

    fprint_list_int(stdout, l2);
    // fprint_list_int_backward(stdout, l2);

    // pop_back(&l2);

    // fprint_list_int(stdout, l2);
    // fprint_list_int_backward(stdout, l2);

    // pop_back(&l2);

    // fprint_list_int(stdout, l2);
    // fprint_list_int_backward(stdout, l2);

    // pop_back(&l2);

    // fprint_list_int(stdout, l2);
    // fprint_list_int_backward(stdout, l2);

    destroy_list(&l2);

    // printf("%p, %p, %d\n", l1.first->prev, l1.last->next, *(int*)(l1.first->data));
    // printf("%p, %p, %c\n", l2.first->next, l2.last->prev, *(char*)(l2.last->data));

}

size_t sizeOfStr(char* str) {
    size_t size = 0;
    int i = 0;
    while (*(str+i) != '\0') {
        size++;
        i++;
    }
    return size;
}

void printArr(void* arr, size_t size) {
    int* res = arr;
    for (size_t i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}
