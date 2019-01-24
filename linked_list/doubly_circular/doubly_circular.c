#include "doubly_circular.h"

//the list used in main is a pointer to the sentinel
linkedlist create_list(){
    linkedlist list = malloc(sizeof(list_element));
    list->next = list;
    list->prev = list;
    list->key = -1;
    list->value = -1;
    return list;
}

linkedlist insert_element(linkedlist list, int key, int value){
    list_element *new_element = malloc(sizeof(list_element));
    list_element *last_element = list->prev;
    last_element->next = new_element;
    new_element->next = list;
    new_element->prev = last_element;
    new_element->key = key;
    new_element->value = value;
    list->prev = new_element;
    return list;
}

linkedlist delete_element(linkedlist list, int key){
    list_element *next_element = list;
    if (list->next == list){
        printf("You cannot delete items in an empty list, pal!\n");
        return list;
    }

    list_element* prev_element = list;
    while(next_element->key != key){
        prev_element = next_element;
        next_element = next_element->next;
        if (next_element == list){
            printf("The list does not contain such key!\n");
            return list;
        }
    }

    printf("Found element! \n\tKey: %d\n\tValue: %d\n",next_element->key,next_element->value);
    printf("Deleting...\n");

    list_element *next_next = next_element->next;
    prev_element->next = next_next;
    next_next->prev = prev_element;
    free(next_element);
    return list;
}

int find_value(linkedlist list, int key){
    list_element *next_element = list;

    while(next_element->key != key){
        next_element = next_element->next;
        if (next_element == list){
            printf("The list does not contain such key! Returning -1...\n");
            return -1;
        }
    }

    printf("Found element! \n\tKey: %d\n\tValue: %d\n",next_element->key,next_element->value);
    return next_element->value;
}

void free_list(linkedlist list){
    printf("DELETING THE REST OF THE LIST...\n");
    while (list->next != list){ 
        list = delete_element(list, list->next->key);
    }
    free(list);
}
