#include "queue.h"

queue make_queue(int initial_len){
    queue q = malloc(sizeof(queue_struct));
    q->length = 0;
    q->head = 0;
    q->tail = 0;
    q->max_len = initial_len;
    q->values = malloc(sizeof(int)*initial_len);
    printf("Queue created with maximum size %d\n",q->max_len);
    return q;
}

int dequeue(queue q){
    if (q->length == 0){
        printf("\nERROR: This queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    int element = q->values[q->head];
    q->head++;
    if (q->head == q->max_len)  q->head = 0;
    q->length--;
    return element;
}

void enqueue(queue q, int element){
    if (q->length == q->max_len){
        printf("\nERROR: This queue does not support more elements!\n\n");
        return;
    }
    q->values[q->tail] = element;
    q->tail++;
    if (q->tail == q->max_len)  q->tail = 0;
    q->length++;
}

void delete_queue(queue q){
    free(q->values);
    free(q);
}
    
