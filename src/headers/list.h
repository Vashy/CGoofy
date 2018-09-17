#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>


// |----|
// |Node|
// |----|

typedef struct Node {
    void* data;
    struct Node* prev;
    struct Node* next;
} Node;

/* Frees data and Node occupied memory. */
void destroy_node(Node*);


// |----|
// |List|
// |----|

typedef struct List {
    Node* first;
    Node* last;
} List;

// --------------
// "Constructors"
// --------------

/* Returns an empty List. */
List new_empty_list();

/* Returns a List containing a singe Node holding the data value.
 *
 * TODO: Memory leak? Data is stored in the heap, so be careful.*/
List new_list(void* data);

/* Returns a List containing a singe Node holding the data value. */
List new_list_from_int(int data);

// --------------
// PUSH functions
// --------------

/* Appends a Node holding the data value to list.
 * 
 * Returns -1 if something went wrong.*/
int push_back(List* list, void* data);

/* Appends a Node holding the int data value to list.
 *
 * TODO: Memory leak? Data is stored in the heap, so be careful.
 * 
 * Returns -1 if something went wrong.*/
int push_back_int(List* list, int data);

/* Appends a Node holding the int char value to list.
 *
 * TODO: Memory leak? Data is stored in the heap, so be careful.
 * 
 * Returns -1 if something went wrong.*/
int push_back_char(List* list, char data);

/* Add a Node holding the data value at the head of the list.
 * 
 * Returns -1 if something went wrong.*/
int push_front(List* list, void* data);

/* Add a Node holding the int data value at the head of the list.
 * 
 * Returns -1 if something went wrong.*/
int push_front_int(List* list, int data);


/* Remove the last element from the List.
 * 
 * Returns -1 if the list is empty, 0 otherwise. */
int pop_back(List* list);

/* Remove the first element from the List.
 * 
 * Returns -1 if the list is empty, 0 otherwise. */
int pop_front(List* list);


// ------
// Memory 
// ------

/* Frees the Node of the argument List. */
void destroy_list(List*);

// -------------------
// Debugging functions
// -------------------

/* Debugging purpose: print nodes' data in the stream. */
void fprint_list_int(FILE* stream, List list);

/* Debugging purpose: print nodes' data in the stream, backward. */
void fprint_list_int_backward(FILE* stream, List list);



#endif