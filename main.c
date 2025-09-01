#include <stdio.h>
#include <stdlib.h>
#include "include/vector.h"
#include "include/Fraction.h"
#include "include/myheader.h"

int main () 
{
    vector* v_int = set_random_vector_int(100);
    for (int i=0; i<vector_size(v_int); i++) {
        printf("%d ", *(int*)vector_get(v_int, i));
    }
    printf("\n");
    vector* v_frc = set_random_vector_frc(100);
    for (int i=0; i<vector_size(v_frc); i++) {
        fraction_print((fraction*)vector_get(v_frc, i));
    }
    printf("\n");
    int *sum = alg_vector(v_int);
    printf("Suma: %d\n", *sum);
    vector_free(v_int);
    vector_free(v_frc);
    free(sum);
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
        fraction *num = fraction_new(rand() % 100, (rand() % 99) + 1); // Denominador no puede ser cero
        vector_add(v, num);
    }
    return v;
}

int *alg_vector(vector *v)
{
    int *op =(int *)malloc(sizeof(int*));
    for (int i=0; i<vector_size(v); i++) {
        *op += *(int*)vector_get(v, i);
    }
    return op;
}