#ifndef MYHEADER_H
#define MYHEADER_H
#include "vector.h"

vector* set_random_vector_int(int size);
vector* set_random_vector_frc(int size);
int busc_valor(vector *v, void *val, int (*cmp)(void *, void *));
int compare_int(void *a, void *b);

#endif