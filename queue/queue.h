#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_struct{
    int length;
    int head;
    int tail;
    int max_len;
    int* values;
} queue_struct;

typedef queue_struct* queue;

queue make_queue(int initial_len);

void sigstop_max();

void sigstop_min();

int dequeue(queue q);

void enqueue(queue q, int element);

void delete_queue(queue q);
