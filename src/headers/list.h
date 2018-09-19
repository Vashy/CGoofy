#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

// |----|
// |Node|
// |----|

/**
 * Node struct. Holds a pointer to any type of data in `data`,
 * a pointer to the previous node in `prev`, and a pointer to the next
 * node in `next`.
*/
typedef struct Node {
    void* data;
    struct Node* prev;
    struct Node* next;
} Node;

/**
 * Frees data and Node occupied memory.
 *
 * @param: the node pointer to destroy.
*/
void destroy_node(Node*);


// |----|
// |List|
// |----|

/**
 * Linked List structure. Holds a sequental list of Nodes pointers.
 * `first` points to the first element of the list, `last` points to the last.
*/
typedef struct List {
    Node* first;
    Node* last;
} List;

// --------------
// "Constructors"
// --------------

/**
 * @returns an empty List.
*/
List new_empty_list();

/**
 * @param data: a pointer to any type of data stored in the heap.
 * @returns a List containing a singe Node holding the data value.
 *
 * TODO: Memory leak? Data is stored in the heap, so be careful.*/
List new_list(void* data);

/**
 * @param data: the int data to initialize the first node with.
 * @returns a List containing a singe Node holding the data value. */
List new_list_from_int(int data);

// --------------
// PUSH functions
// --------------

/**
 * Appends a Node holding the data value to list.
 *
 * @returns -1 if something went wrong.*/
int push_back(List* list, void* data);

/**
 * Appends a Node holding the int data value to list.
 *
 * TODO: Memory leak? Data is stored in the heap, so be careful.
 *
 * @returns -1 if something went wrong.*/
int push_back_int(List* list, int data);

/**
 * Appends a Node holding the int char value to list.
 *
 * TODO: Memory leak? Data is stored in the heap, so be careful.
 *
 * @returns -1 if something went wrong.*/
int push_back_char(List* list, char data);

/**
 * Add a Node holding the data value at the head of the list.
 *
 * @returns -1 if something went wrong.*/
int push_front(List* list, void* data);

/**
 * Add a Node holding the int data value at the head of the list.
 *
 * @param list: a pointer to the list.
 * @returns -1 if something went wrong
*/
int push_front_int(List* list, int data);

// -------------
// POP functions
// -------------

/**
 * Remove the last element from the List.
 *
 * @param list: a pointer to the list.
 * @returns -1 if the list is empty, 0 otherwise. */
int pop_back(List* list);

/**
 * Remove the first element from the List.
 *
 * @param list: a pointer to the list.
 * @returns -1 if the list is empty, 0 otherwise.
*/
int pop_front(List* list);

// -------
// Utility
// -------

/**
 * @param list: a pointer to the list.
 * @param data: the integer you want
 * @returns a positive integer if the list contains a node with the data int
 * (the number of steps needed to find the element), 0 otherwise.
*/
int contains_int(List* list, int data);

/**
 * Fetches `data` in the list, returning the pointer to the first Node
 * containing that value
 *
 * @param list: a pointer to the list.
 * @param data: data to fetch.
 * @returns a pointer to the first Node having *(Node->data) = data,
 * NULL if there are no match
*/
Node* fetch_int(List* list, int data);

/**
 * Joins the two list parameters into list1, like `list1 = list1 + list2`.
 *
 * @param list1: side-effected list.
 * @param list2: other list.
 * @returns the list1's `first` Node.
*/
Node* join_lists(List* list1, List* list2);


// ------
// Memory
// ------

/**
 * Frees the Node of the argument List.
 * @param list: a pointer to the list.
*/
void destroy_list(List*);

// -------------------
// Debugging functions
// -------------------

/** For Debugging purpose: print nodes' data in the stream. */
void fprint_list_int(FILE* stream, List list);

/** For Debugging purpose: print nodes' data in the stream, backward. */
void fprint_list_int_backward(FILE* stream, List list);


#endif