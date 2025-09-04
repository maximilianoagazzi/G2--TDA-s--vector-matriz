#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/vector.h"
#include "include/Fraction.h"
#include "include/myheader.h"

int main () 
{
    vector* v_int = set_random_vector_int(100);
    printf("El vector de enteros es: \n\n");
    for (int i=0; i<vector_size(v_int); i++) {
        printf("%d ", *(int*)vector_get(v_int, i));
    }
    printf("\n");
    //Ejercicio 2

    vector* v_frc = set_random_vector_frc(100);
    printf("\nEl vector de fracciones es: \n\n");
    for (int i=0; i<vector_size(v_frc); i++) {
        fraction_print((fraction*)vector_get(v_frc, i));
    }  //Hasta acá se crean los vectores int y fraction y se imprimen
    //Ejercicio 3

    vector* v_frc_sum = sum_vector(v_frc, v_frc, sum_frc);
    printf("\nEl vector de suma de dos vectores fracciones es: \n\n");
    for (int i=0; i<vector_size(v_frc_sum); i++) {
        fraction_print((fraction*)vector_get(v_frc_sum, i));
    }  //Este es el fragmento de suma de vectores
    //Ejercicio 5

    void *min_int = valor_min_or_max(v_int, compare_int, "min");
    printf("\nEl valor minimo del vector de enteros es: %d\n", *(int*)min_int); //Valor mínimo del vector de enteros
    void *max_int = valor_min_or_max(v_int, compare_int, "max");
    printf("El valor maximo del vector de enteros es: %d\n", *(int*)max_int); //Valor máximo del vector de enteros
    //Ejercicio 6

    int val = 41;
    int cant = busc_valor(v_int, &val, compare_int);
    printf("\nEl valor %d se encuentra %d veces en el vector de enteros\n", val, cant);  //Esta fragmento busca las apariciones de un valor en el vector
    //Ejercicio 7

    printf("\nEl valor maximo del vector de enteros se repite: %d veces\n", valor_max_1rec(v_int, compare_int)); //lo recorre 1 vez 
    //Ejercicio 8

    vector *result = ordenar_vector(v_frc, compare_frc);
    printf("\nEl vector de fracciones ordenado es: \n\n");
    for (int i=0; i<vector_size(result); i++) {
        fraction_print((fraction*)vector_get(result, i));
    }
    //Ejercicio 9

    int pos = primera_aparicion(v_frc, vector_get(v_frc, 0), compare_frc);
    printf("\nLa primera aparicion es en la posicion: %d\n\n", pos);
    //Ejercicio 10

    vector_free(result);
    vector_free(v_frc_sum);
    vector_free(v_int);
    vector_free(v_frc);  //Liberar memoria
    return 0;
}

vector* set_random_vector_int(int size)  //Ejercicio 2
{
    vector *v = vector_new_with(size);
    for (int i=0; i<size; i++) {
        int *num = (int*)malloc(sizeof(int));
        *num = rand() % 100; // Números aleatorios entre 0 y 99
        vector_add(v, num);
    }
    return v;
}

vector* set_random_vector_frc(int size) //Ejercicio 3
{
    vector *v = vector_new_with(size);
    for (int i=0; i<size; i++) {
        fraction *num = fraction_new(rand() % 100, (rand() % 99) + 1); // Denominador no puede ser cero
        vector_add(v, num);
    }
    return v;
}

vector* sum_vector(vector *v1, vector *v2, void* (*sum)(void*, void*)) //Ejercicio 5
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

void* sum_frc(void* a, void* b) //Ejercicio 5
{
    fraction *f1 = (fraction*)a;
    fraction *f2 = (fraction*)b;
    return (void*)fraction_add(f1, f2);
}

void *valor_min_or_max(vector *v, int (*cmp)(void*, void*), char *type) //Ejercicio 6
{
    void *valor, *extrm;
    if(vector_size(v) == 0) {
        return NULL; // Vector vacío
    }
    extrm = vector_get(v, 0);
    for(int i=1; i<vector_size(v); i++) {
        valor = vector_get(v, i);
        if (strcmp(type, "min") == 0) {
            if(cmp(valor, extrm) < 0) {
                extrm = valor;
            }
        }
        if (strcmp(type, "max") == 0) {
            if(cmp(valor, extrm) > 0) {
                extrm = valor;
            }
        }
    }
    return extrm;
}

int compare_int(void *a, void *b) { //Ejercicio 6
    int vec = *(int*)a;
    int val = *(int*)b;
    return (vec - val);
}

int busc_valor(vector *v, void *val, int (*cmp)(void *, void *)) //Ejercicio 7
{
    int cant = 0;
    for(int i=0; i<vector_size(v); i++) {
        if(cmp(vector_get(v, i), val) == 0) {
            cant++;
        }
    }
    return cant;
}

int valor_max_1rec(vector *v, int (*cmp)(void*, void*)) //Ejercicio 8
{
    void *valor, *extrm;
    int cnt = 1;
    if(vector_size(v) == 0) {
        return -1; // Vector vacío
    }
    extrm = vector_get(v, 0);
    for(int i=1; i<vector_size(v); i++) {
        valor = vector_get(v, i);
        if(cmp(valor, extrm) > 0) {
            extrm = valor;
            cnt = 1;
        } else if (cmp(valor, extrm) == 0) {
            cnt++;
        }
    }
    return cnt;
}

vector *ordenar_vector(vector *v, int (*ord)(void *, void *)) //Ejercicio 9
{
    vector *result = vector_new_with(vector_size(v));
    char swapped = 1;
    int size = vector_size(v);
    void *aux;
    for (int i=0; i<size; i++) {
        vector_add(result, vector_get(v, i));
    }
    while ((size > 1) && (swapped != 0)) {
        swapped = 0;
        for (int i=1; i<size; i++) {
            if (ord(vector_get(result, i-1), vector_get(result, i)) > 0) {
                aux = vector_get(result, i-1);
                vector_set(result, i-1, vector_get(result, i));
                vector_set(result, i, aux);
                swapped = 1;
            }
        }
        size--;
    }
    return result;
}

int compare_frc(void *a, void *b) //Ejercicio 9
{
    return fraction_cmp((fraction*)a,(fraction*)b);
}

int primera_aparicion(vector *v, void *val, int (*cmp)(void *, void *)) //Ejercicio 10
{
    int prim = -1;
    vector *v_orden = ordenar_vector(v, cmp);
    for(int i=0; i<vector_size(v); i++) {
        vector_set(v, i, vector_get(v_orden, i));
        if(vector_get(v, i) == val && prim == -1) {
            prim = i+1;
        }
    }
    vector_free(v_orden);
    return prim;
}

