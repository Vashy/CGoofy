#include "../headers/vec.h"
#include <stdlib.h>
// #include <stdio.h>


// --------------
// "Constructors"
// --------------

Vec new_int_vec() {
    return new_int_vec_capacity(5);
}

Vec new_int_vec_capacity(long int capacity) {
    Vec v;
    v.size = 0;
    v.capacity = capacity;

    // v.arr is a pointer of pointers
    // so malloc needs sizeof(pointer*)
    v.arr = malloc(capacity*sizeof(int*));
    return v;
}


// -------------
// PUSH functions
// -------------

int vec_push_back(Vec* vec, void* data) {
    if (vec->size < vec->capacity) {
        vec->arr[vec->size] = data;
        vec->size++;
        return 0;
    }

    // case size >= capacity, need to realloc
    vec->capacity = vec->capacity*2;
    vec->arr = realloc(vec->arr, vec->capacity*sizeof(int*));
    if (vec->arr == NULL) // cannot alloc memory
        return -1;

    printf("Realloc-ing...\n");
    vec->arr[vec->size] = data;
    vec->size++;

    return 0;
}

int vec_push_back_int(Vec* vec, int data) {
    int* value_to_push = (int*)malloc(sizeof(int));
    *value_to_push = data;

    return vec_push_back(vec, value_to_push);
}


// -------------
// POP functions
// -------------

int vec_pop_back(Vec* vec) {
    if (vec->size == 0) // cannot pop from an empty array
        return -1;

    free(vec->arr[vec->size-1]); // frees memory
    vec->size--;
    return 0;
}


int* vec_get_int(Vec* vec, int index) {
    if (index >= vec->size) {
        fprintf(stderr, "ERROR: Index out of bounds.\nExit code: %d\n", EXIT_FAILURE);
        exit(EXIT_FAILURE);
    }
    return vec->arr[index];
}

void fprint_vec_int(FILE* outstream, Vec* vec) {
    for (int i = 0; i < vec->size; i++) {
        fprintf(outstream, "%d ", *vec_get_int(vec, i));
    }
    fprintf(outstream, "\n");
}

void delete_vec_int(Vec* vec) {
    for (int i = 0; i < vec->size; i++) { //frees every cell
        free(vec_get_int(vec, i));
    }
    //free arr
    free(vec->arr);
}