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
    //if (first_element != NULL){
    //    printf("Inserted key %d. It points to element of key %d\n",new_element->key,first_element->key);
    //}
    //else{
    //    printf("Inserted key %d. It points to element of key NULL\n",new_element->key);
    //}
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

 //   printf("Found element! \n\tKey: %d\n\tValue: %d\n",next_element->key,next_element->value);
    //if (next_element->next != NULL)    printf("It points to element of key %d\n",next_element->next->key);
  //  printf("Deleting...\n");

    if (prev_element == next_element){
        list = next_element->next;
    }
    else{
        prev_element->next = next_element->next;
    }
    free(next_element);
    return list;
}

int find_element(linkedlist list, int key){
    list_element *next_element = list;
    
    if (list == NULL){
        printf("The list does not contain such key! Returning -1...\n");
        return -1;
    }
    while(next_element->key != key){
        next_element = next_element->next;
        if (next_element == NULL){
            printf("The list does not contain such key! Returning -1...\n");
            return -1;
        }
    }
    
    
//    printf("Found element! \n\tKey: %d\n\tValue: %d\n",next_element->key,next_element->value);
    return next_element->value;
}

void free_list(linkedlist list){
    //printf("DELETING THE REST OF THE LIST...\n");
    while (list != NULL){
        list = delete_element(list, list->key);
    }
}
