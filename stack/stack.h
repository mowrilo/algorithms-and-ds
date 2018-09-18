// coding a dynamically allocated stack of ints in c

#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int capacity;
    int *st;
    int size;
} stack;

stack make_stack(void);

void push(stack *st, int element);

int pop(stack *st);

int max(stack *st);

int at(stack *st, int index);

int find(stack *st, int element);

// mode can be: 
//  'p' - resized up
//  'm' - resized down
void resize(stack *st, char mode);

void free_stack(stack *st);
