// tentative of a c++ vector of ints in c

#include <stdlib.h>

typedef struct vector{
    int capacity;
    int *vec;
    int size;
} vector;

vector vector();

void push_back(vector vec, int element);

int pop_back(vector vec);

int pop(vector vec, int index);

int max(vector vec);

int at(vector vec, int index);

int find(vector vec, int element);

void resize(vector vec);
