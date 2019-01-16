#include "singly_linkedlist.h"

int main(){
    linkedlist list = create_list();
    int i;
    for (i=0; i<20; i++){
        list = insert_element(list, i, i*10);
    }

    for (i=0; i<40; i+=2){
        list = delete_element(list, i);
    }

    return 0;
}
