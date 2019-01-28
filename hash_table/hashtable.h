// Hash table with chaining
// Author: Murilo V. F. Menezes
#include <stdio.h>
#include <stdlib.h>
#include "../linked_list/singly/singly_linkedlist.h"

#define TAB_SIZE 107

typedef linkedlist* table;

int hash(int key);

table create_hash();

table insert_hash(table t, int key, int value);

table remove_hash(table t, int key);

int find_hash(table t, int key);

void free_hash(table t);
