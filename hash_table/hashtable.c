#include "hashtable.h"

#define TAB_SIZE 107

table create_hash(){
    linkedlist *table = malloc(sizeof(linkedlist) * TAB_SIZE);
    int i;
    for (i=0; i<TAB_SIZE; i++){
        table[i] = create_list();
    }
    return table;
}

int hash(int key){
    return key % TAB_SIZE;
}

table insert_hash(table t, int key, int value){
    if (key == 94)  printf("\nINSERTED\n");
    int position = hash(key);
    t[position] = insert_element(t[position], key, value);
    return t;
}

table remove_hash(table t, int key){
    if (key == 94)  printf("\nREMOVED\n");
    int position = hash(key);
    t[position] = delete_element(t[position], key);
    return t;
}

int find_hash(table t, int key){
    int position = hash(key);
    int element = find_element(t[position], key);
    return element;
}

void free_hash(table t){
    int i;
    for (i=0; i<TAB_SIZE; i++){
        free_list(t[i]);
    }
    free(t);
}
