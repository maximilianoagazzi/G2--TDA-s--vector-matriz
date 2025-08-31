#include <stdio.h>
#include <stdlib.h>
#include "lib/vector.h"
#include "myheader.h"

int main () 
{
    vector* v = set_random_vector(100);
    for (int i=0; i<vector_size(v); i++) {
        printf("%d ", *(int*)vector_get(v, i));
    }
    return 0;
}

vector* set_random_vector(int size)
{
    vector *v = vector_new_with(size);
    for (int i=0; i<size; i++) {
        int *num = (int*)malloc(sizeof(int));
        *num = rand() % 100; // Números aleatorios entre 0 y 99
        vector_add(v, num);
    }
    return v;
}