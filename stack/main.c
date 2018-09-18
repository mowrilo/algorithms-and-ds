#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
    stack st = make_stack();
    int i;
    int n_elements = 10;
    printf("\nStack capacity: %d\n",st.capacity);
    printf("Pushing elements...\n");
    for (i=0; i<n_elements; i++){
        push(&st, i);
        printf("%d\t",i);
    }
    printf("\nstack capacity: %d\n",st.capacity);
    
    printf("Popping elements...\n");
    for (i=0; i<n_elements; i++){
        int element = pop(&st);
        printf("%d\t", element);
    }
    printf("\nStack capacity: %d\n",st.capacity);

    free_stack(&st);
    return 0;
}
