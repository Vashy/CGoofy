#include "../headers/list.h"
#include <stdlib.h>

// |----|
// |Node|
// |----|


void destroy_node(Node* node) {
    // printf("Destroying node with data = %d ...\n", *(int*)(node->data)); // for Debugging
    free(node->data);
    free(node);
}

// |----|
// |List|
// |----|

// --------------
// "Constructors"
// --------------

List new_list(void* data) {
    Node* f = (Node*)malloc(sizeof(Node));
    if (f == NULL)
        exit(EXIT_FAILURE);

    List l;

    // a single-node list does not have prev and next Nodes
    f->next = NULL;
    f->prev = NULL;

    f->data = data;
    l.first = l.last = f;

    return l;
}

List new_empty_list() {
    List l;
    l.first = l.last = NULL;
    return l;
}

List new_list_from_int(int data) {
    int* val = (int*)malloc(sizeof(int));
    *val = data;
    return new_list(val);
}

// --------------
// PUSH functions
// --------------

int push_back(List* list, void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) // No memory
        return -1;

    new_node->data = data; // holding data

    // case empty list
    if (list->last == NULL) {
        //single Node, it does not have any prev or next node
        new_node->prev = NULL;
        new_node->next = NULL;

        list->first = list->last = new_node;
        return 0; // All ok
    }

    // case 1 or more nodes

    new_node->prev = list->last; // new last Node prev points to old last Node
    new_node->next = NULL; // new last Node doesn't have a next Node

    list->last->next = new_node;
    list->last = list->last->next;

    return 0; // All ok
}

int push_front(List* list, void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) // No memory
        return -1;

    new_node->data = data; // holding data

    // case empty list
    if (list->first == NULL) {

        new_node->next = new_node->prev = NULL;
        list->first = list->last = new_node;
        return 0;
    }

    // case 1 or more nodes

    new_node->next = list->first;
    new_node->prev = NULL;
    list->first->prev = new_node;
    list->first = list->first->prev;
    return 0;
}


int push_back_int(List* list, int data) {
    // MEMORY
    int* val = (int*)malloc(sizeof(int));
    *val = data;
    if (val == NULL)
        return -1;
    return push_back(list, val);
}

int push_front_int(List* list, int data) {
    int* val = (int*)malloc(sizeof(int));
    *val = data;
    if (val == NULL)
        return -1;
    return push_front(list, val);
}

int push_back_char(List* list, char data) {
    char* val = (char*)malloc(sizeof(char));
    *val = data;
    if (val == NULL)
        return -1;
    return push_back(list, val);
}

// -------------
// POP functions
// -------------

int pop_back(List* list) {
    if (list->first == NULL)
        return -1;
    Node* temp = list->last;
    list->last = list->last->prev;
    list->last->next = NULL;

    destroy_node(temp);

    return 0;
}

int pop_front(List* list) {
    if (list->first == NULL)
        return -1;

    Node* temp = list->first;
    list->first = list->first->next;
    list->first->prev = NULL;

    destroy_node(temp);

    return 0;
}

// -------
// Utility
// -------

int contains_int(List* list, int data) {

    // temp node
    Node* node = list->first;

    int steps = 0; //number of steps
    while (node != NULL) {
        steps++;
        if (*(int*)node->data == data)
            return steps;
        node = node->next;
    }
    return 0;
}

Node* fetch_int(List* list, int data) {
    // temp node
    Node* node = list->first;

    while (node != NULL) {
        if (*(int*)node->data == data)
            break; // found!
        node = node->next;
    }

    // in case of no match, NULL will be returned
    return node;
}

Node* join_lists(List* list1, List* list2) {
    // l1->last points to l2->first. l1->last will be l2->last
    list1->last->next = list2->first;
    list1->last = list2->last;
    return list1->first;
}


// ------
// Memory
// ------

void destroy_list(List* list) {
    while (list->first != NULL) {
        Node* node = list->first;
        list->first = list->first->next;
        destroy_node(node);
    }
}


// -------------------
// Debugging functions
// -------------------

void fprint_list_int(FILE* stream, List list) {
    Node* node = list.first;
    while (node != NULL) {
        fprintf(stream, "%d ", *(int*)(node->data));
        node = node->next;
    }
    fprintf(stream, "\n");
}

void fprint_list_int_backward(FILE* stream, List list) {
    Node* node = list.last;
    while (node != NULL) {
        fprintf(stream, "%d ", *(int*)(node->data));
        node = node->prev;
    }
    fprintf(stream, "\n");
}
