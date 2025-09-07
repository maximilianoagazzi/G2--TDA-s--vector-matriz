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

    printf("\nLa suma de todas las fracciones del vector es: \n");
    fraction_print((fraction*)alg_vector(v_frc, suma_frc));  //Este es el fragmento de suma de fracciones
    //Ejercicio 4

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

    vector *result = ordenar_vector_bubble(v_frc, compare_frc);
    printf("\nEl vector de fracciones ordenado por bubble es: \n\n");
    for (int i=0; i<vector_size(result); i++) {
        fraction_print((fraction*)vector_get(result, i));
    }
    //Ejercicio 9

    int pos = primera_aparicion(v_frc, vector_get(v_frc, 0), compare_frc);
    printf("\nLa primera aparicion es en la posicion: %d\n\n", pos); //La aparicion del elemento elejido en el vector ordenado
    //Ejercicio 10

    vector *result2 = ordenar_vector_insertion(v_frc, compare_frc);
    printf("\nEl vector de fracciones ordenado por insertion es: \n\n");
    for (int i=0; i<vector_size(result2); i++) {
        fraction_print((fraction*)vector_get(result2, i));
    } 
    //Ejercicio 11

    vector_sort(v_int, compare_int); //ordena v_int en si mismo
    printf("\nEl vector de enteros ordenado en si mismo es: \n\n");
    for (int i=0; i<vector_size(v_int); i++) {
        printf("%d ", *(int*)vector_get(v_int, i));
    } 
    //Ejercicio 12

    int a = 50;
    int *valor = &a;
    int busq = vector_sequential_search(v_int, valor, compare_int);  //Busqueda sequencial de a lo sumo vector_size() para encontrar el valor
    if (busq != -1) {
        printf("\n\nEl valor %d se encuentra en la posicion: %d\n", a, busq);
    } else {
        printf("\n\nEl valor %d no se encuentra en el vector\n", a);
    }
    busq = vector_binary_search(v_int, valor, compare_int);  //Busqueda binaria de a lo sumo log2(vector_size()) para encontrar el valor
    if (busq != -1) {
        printf("\nEl valor %d se encuentra en la posicion: %d\n", a, busq);
    } else {
        printf("\nEl valor %d no se encuentra en el vector\n", a);
    }
    //Ejercicio 13

    vector *no_repetidos = eliminar_repetidos(v_frc, compare_frc);
    printf("\nEl vector de fracciones sin repetidos es: \n\n");
    for (int i=0; i<vector_size(no_repetidos); i++) {
        fraction_print((fraction*)vector_get(no_repetidos, i));
    } //En este caso no se repiten las fracciones asi que el vector resultante es el mismo
    //Ejercicio 14


    for(int i=0; i<vector_size(v_frc); i++) {
        fraction_destroy((fraction*)vector_get(v_frc, i));
    } //Libera cada fraccion del vector de fracciones
    vector_free(v_frc);
    for(int i=0; i<vector_size(v_frc_sum); i++) {
        fraction_destroy((fraction*)vector_get(v_frc_sum, i));
    } //Libera cada fraccion del vector de suma de fracciones
    vector_free(v_frc_sum);
    for(int i=0; i<vector_size(result); i++) {
        fraction_destroy((fraction*)vector_get(result, i));
    } //Libera cada fraccion del vector ordenado por bubble
    vector_free(result);
    for(int i=0; i<vector_size(result2); i++) {
        fraction_destroy((fraction*)vector_get(result2, i));
    } //Libera cada fraccion del vector ordenado por insertion
    vector_free(result2);
    for(int i=0; i<vector_size(no_repetidos); i++) {
        fraction_destroy((fraction*)vector_get(no_repetidos, i));
    } //Libera cada fraccion del vector sin elementos repetidos
    vector_free(no_repetidos); 

    vector_free(v_int); //Liberar memoria
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

void *alg_vector(vector *v, void *(*alg)(void*, void*)) //Ejercicio 4 AUN NO FUNCIONA
{
    void *op = NULL;
    for (int i=0; i<vector_size(v); i++) {
        op = alg(op, vector_get(v, i));
    }
    return op;
}

void *suma_frc(void *a, void *b) //Ejercicio 4
{
    fraction *sum;
    if (a == NULL) {
        sum = fraction_new(0, 1);
    } else {
        sum = (fraction*)a;
    }
    fraction *num = (fraction*)b;
    sum = fraction_add(sum, num);
    if (a != NULL) {
        fraction_destroy((fraction*)a);
    }
    return (void *)sum;
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

vector *ordenar_vector_bubble(vector *v, int (*ord)(void *, void *)) //Ejercicio 9
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
    vector *v_orden = ordenar_vector_bubble(v, cmp);
    for(int i=0; i<vector_size(v); i++) {
        vector_set(v, i, vector_get(v_orden, i));
        if(vector_get(v, i) == val && prim == -1) {
            prim = i+1;
        }
    }
    vector_free(v_orden);
    return prim;
}

vector *ordenar_vector_insertion(vector *v, int (*ord)(void *, void *)) //Ejercicio 11
{
    vector *result = vector_new_with(vector_size(v));
    for(int i=1; i<vector_size(v); i++) {
        void *aux = vector_get(v, i);
        int pos = 0;
        while (pos < vector_size(result) && ord(aux, vector_get(result, pos)) > 0) {
            pos++;
        }
        vector_insert(result, pos, aux);
    }
    vector_insert(result, 0, vector_get(v, 0));
    return result;
}

vector *eliminar_repetidos(vector *v, int (*cmp)(void *, void *)) //Ejercicio 14
{
    vector *result = vector_new_with(vector_size(v));
    for(int i=0; i<vector_size(v); i++) {
        void *aux = vector_get(v, i);
        int repetido = 0;
        for(int j=0; j<vector_size(result); j++) {
            if(cmp(vector_get(result, j), aux) == 0) {
                repetido = 1;
                break;
            }
        }
        if(repetido == 0) {
            vector_add(result, aux);
        }
    }
    return result;
}

vector *elementos_mezclados(vector *v1, vector *v2, int (*cmp)(void *,void *)) //Ejercicio 15
{

}