#include <stdio.h>
#include <stdlib.h>
#include "include/vector.h"
#include "include/Fraction.h"
#include "include/myheader.h"

vector* sum_vector(vector *v1, vector *v2, void* (*sum)(void*, void*));
void* sum_frc(void* a, void* b);

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
    }  //Hasta acá se crean los vectores int y fraction y se imprimen

    printf("\n");
    int val = 41;
    int cant = busc_valor(v_int, &val, compare_int);
    printf("El valor %d se encuentra %d veces en el vector de enteros\n\n", val, cant);  //Esta fragmento busca las apariciones de un valor en el vector

    vector* v_frc_sum = sum_vector(v_frc, v_frc, sum_frc);
    for (int i=0; i<vector_size(v_frc_sum); i++) {
        fraction_print((fraction*)vector_get(v_frc_sum, i));
    }  //Este es el fragmento de suma de vectores

    vector_free(v_frc_sum);
    vector_free(v_int);
    vector_free(v_frc);  //Liberar memoria
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

int busc_valor(vector *v, void *val, int (*cmp)(void *, void *))
{
    int cant = 0;
    for(int i=0; i<vector_size(v); i++) {
        if(cmp(vector_get(v, i), val) == 0) {
            cant++;
        }
    }
    return cant;
}

int compare_int(void *a, void *b) {
    int vec = *(int*)a;
    int val = *(int*)b;
    return (vec - val);
}

vector* sum_vector(vector *v1, vector *v2, void* (*sum)(void*, void*))
{
    vector *result;
    if (vector_size(v1) != vector_size(v2)) {
        return NULL; // Vectores de diferente tamaño
    }
    result = vector_new_with(vector_size(v1));
    for (int i=0; i<vector_size(v1); i++) {
        void *elem = sum(vector_get(v1, i), vector_get(v2, i));
        vector_add(result, (fraction*)elem);
    }
    return result;
}

void* sum_frc(void* a, void* b)
{
    fraction *f1 = (fraction*)a;
    fraction *f2 = (fraction*)b;
    return (void*)fraction_add(f1, f2);
}