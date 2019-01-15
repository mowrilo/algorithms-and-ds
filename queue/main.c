#include "queue.h"

void print_size(queue q){
    printf("Size of queue: %d\n",q->length);
}

int main(int argc, char* argv[]){
    int max_length = 10;
    queue q = make_queue(max_length);
    printf("\n\n");
    int i;
    printf("Enqueuing...\n");
    for (i=0; i<11; i++){
        enqueue(q,i);
        printf("\t");
        print_size(q);
    }
    printf("\n");
    printf("Dequeuing...\n");
    for (i=0; i<5; i++){
        int el = dequeue(q);
        printf("\t");
        print_size(q);
        printf("\tElement dequeued: %d\n", el);
    }
    printf("\n");
    printf("Enqueuing...\n");
    for (i=10; i<15; i++){
        enqueue(q,i);
        printf("\t");
        print_size(q);
    }
    printf("\n");
    printf("Dequeuing...\n");
    for (i=0; i<7; i++){
        int el = dequeue(q);
        printf("\t");
        print_size(q);
        printf("\tElement dequeued: %d\n", el);
    }
    return 0;
}
