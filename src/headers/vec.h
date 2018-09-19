#ifndef VEC_H
#define VEC_H

#include <stdio.h>

/** Vec is a dinamically-sized array.
*/
typedef struct Vec {
    void** arr;
    unsigned long size;
    unsigned long capacity;
} Vec;


// --------------
// "Constructors"
// --------------

/**
 * @returns a new vector which should contains integers, with a starting
 * capacity of 5.
*/
Vec new_int_vec();

/** @returns a new vector which should contains integers, with a starting
 * capacity of `capacity`.
 *
 * @param capacity: vector capacity.
*/
Vec new_int_vec_capacity(long int capacity);


// --------------
// PUSH functions
// --------------

/**
 * Generic push_back functions. You shouldn't call this function directly, or it will
 * cause memory corruptions.
*/
int vec_push_back(Vec* vec, void* data);

/** Push back `data` integer in the "tail" of the vector.
 *
 * @returns -1 if memory for the new cell cannot be allocated, 0 otherwise.
*/
int vec_push_back_int(Vec* vec, int data);

// -------------
// POP functions
// -------------

/** Pop the last element of the vector vec.
 *
 * @returns -1 if vec->size is 0
*/
int vec_pop_back(Vec* vec);

// ---
// GET
// ---

/** @returns i-cell of vec, or aborts on a arrays out of bounds.
 * @param i: index of the cell
*/
int* vec_get_int(Vec* vec, int index);

// ---------
// DEBUGGING
// ---------

void fprint_vec_int(FILE*, Vec*);

// ------
// MEMORY
// ------

/** Frees the memory occupied by vec and all of its cells.
*/
void delete_vec_int(Vec* vec);

#endif