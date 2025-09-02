#ifndef MYHEADER_H
#define MYHEADER_H
#include "vector.h"

vector* set_random_vector_int(int size);
vector* set_random_vector_frc(int size);
void *alg_vector(vector *v, void * (*alg)(void*, void*));

#endif