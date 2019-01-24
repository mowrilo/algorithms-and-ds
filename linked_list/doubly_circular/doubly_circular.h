// A circular, doubly-linked list with sentinel
// Author: Murilo V. F. Menezes
//
#include <stdio.h>
#include <stdlib.h>

typedef struct list_element{
    int key;
    int value;
    struct list_element *next;
    struct list_element *prev;
} list_element;

typedef list_element* linkedlist;

linkedlist create_list();

linkedlist insert_element(linkedlist list, int key, int value);

linkedlist delete_element(linkedlist list, int key);

int find_element(linkedlist list, int key);

void free_list(linkedlist list);
