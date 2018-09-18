#include "stack.h"

stack make_stack(void){
    stack st;
    st.capacity = 36;
    st.size = 0;
    st.st = malloc(sizeof(int) * st.capacity);
    return st;
}

void push(stack *st, int element){
    if (st->size == st->capacity){
        resize(st, 'p');
    }

    st->st[st->size] = element;

    st->size++;
}

int pop(stack *st){
    int element = st->st[st->size - 1];
    st->st[st->size - 1] = 0;
    st->size--;
    if (st->size <= (st->capacity/4)){
        resize(st, 'm');
    }
    return element;
}

//int remove(stack *st, int index){
//    
//    if (index > st->size){
//        raise(SIGSEGV);
//    }
//    
//    int i;
//    int val = st[index];
//    for (i=index+1; i<st->size; i++){
//        st->st[i-1] = st->st[i];
//    }
//
//    st->size--;
//
//    if (st->size <= (st->capacity/4)){
//        resize(st, 'm');
//    }
//
//    return val;
//}

int max(stack *st){
    int val = INT_MIN;
    int i;
    for (i=0; i<st->size; i++){
        if (st->st[i] > val){
            val = st->st[i];
        }
    }
    return val;
}

int at(stack *st, int index){
    if (index > st->size){
        raise(SIGSEGV);
    }
    return st->st[index];
}

int find(stack *st, int element){
    int found = 0;
    int i;
    return 0;
}

void resize(stack *st, char mode){
    int new_capacity;
    if (mode == 'p'){
        new_capacity = st->capacity * 2;
    }
    else if (mode == 'm'){
        new_capacity = st->capacity/2;
    }
    st->st = realloc(st->st,sizeof(int)*new_capacity);
    st->capacity = new_capacity;
}

void free_stack(stack *st){
    free(st->st);
}
