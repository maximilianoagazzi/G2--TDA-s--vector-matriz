#include <stdio.h>
#include <stdlib.h>
#include "include/vector.h"
#include "include/Fraction.h"
#include "myheader.h"

int main () 
{
    vector* v = set_random_vector_int(100);
    for (int i=0; i<vector_size(v); i++) {
        printf("%d ", *(int*)vector_get(v, i));
    }
    return 0;
}

vector* set_random_vector_int(int size)
{
    vector *v = vector_new_with(size);
    for (int i=0; i<size; i++) {
        int *num = (int*)malloc(sizeof(int));
        *num = rand() % 100; // Números aleatorios entre 0 y 99
        vector_add(v, num);
    }
    return v;
}

vector* set_random_vector_frc(int size)
{
    vector *v = vector_new_with(size);
    for (int i=0; i<size; i++) {
        Fraction *num = (int*)malloc(sizeof(int));
        *num = rand() % 100; // Números aleatorios entre 0 y 99
        vector_add(v, num);
    }
    return v;
}