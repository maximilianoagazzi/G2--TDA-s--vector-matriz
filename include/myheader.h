#ifndef MYHEADER_H
#define MYHEADER_H
#include "vector.h"

vector* set_random_vector_int(int size);
vector* set_random_vector_frc(int size);
int busc_valor(vector *v, void *val, int (*cmp)(void *, void *));
void *alg_vector(vector *v, void *(*alg)(void*, void*));
vector* sum_vector(vector *v1, vector *v2, void* (*sum)(void*, void*));
void *valor_min_or_max(vector *v, int (*cmp)(void*, void*), char *type);
int valor_max_1rec(vector *v, int (*cmp)(void*, void*));
vector *ordenar_vector_bubble(vector *v, int (*ord)(void *, void *));
int primera_aparicion(vector *v, void *val, int (*cmp)(void *, void *));
vector *ordenar_vector_insertion(vector *v, int (*ord)(void *, void *));

void *suma_frc(void *a, void *b);
int compare_int(void *a, void *b);
void* sum_frc(void* a, void* b);
int compare_frc(void *a, void *b);

#endif