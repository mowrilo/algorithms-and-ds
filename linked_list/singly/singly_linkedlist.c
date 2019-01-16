#include "singly_linkedlist.h"

linkedlist create_list(){
    linkedlist list;
    list = NULL;
    return list;
}

linkedlist insert_element(linkedlist list, int key, int value){
    list_element *first_element = list;
    list_element *new_element = malloc(sizeof(list_element));
    new_element->next = first_element;
    new_element->key = key;
    new_element->value = value;
    list = new_element;
    return list;
}

linkedlist delete_element(linkedlist list, int key){
    list_element *next_element = list;
    if (list == NULL){
        printf("You cannot delete items in an empty list, pal!\n");
        return list;
    }
    
    list_element* prev_element = list;
    while(next_element->key != key){
        prev_element = next_element;
        next_element = next_element->next;
        if (next_element == NULL){
            printf("The list does not contain such key!\n");
            return list;
        }
    }

    printf("Found element! \n\tKey: %d\n\tValue: %d\n",next_element->key,next_element->value);
    printf("Deleting...\n");

    prev_element->next = next_element->next;
    free(next_element);
    return list;
}

int find_value(linkedlist list, int key){
    list_element *next_element = list;
    
    while(next_element->key != key){
        next_element = next_element->next;
        if (next_element == NULL){
            printf("The list does not contain such key! Returning -1...\n");
            return -1;
        }
    }
    
    printf("Found element! \n\tKey: %d\n\tValue: %d\n",next_element->key,next_element->value);
    return next_element->value;
}

