#include "hashtable.h"

int main(){

    table t = create_hash();

    int i;
    for (i=0; i<200; i++){
        t = insert_hash(t, i, i+1);
    }


    for (i=0; i<200; i+=2){
        t = remove_hash(t,i);
    }

    for (i=0; i<200; i++){
        int val = find_hash(t, i);
        if (val > -1)   printf("\nFound! Key: %d\tValue:%d\n", i, val);
    }

    free_hash(t);
    return 0;
}
