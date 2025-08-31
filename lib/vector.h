#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector vector;

vector* vector_new(); // Crea el vector
vector* vector_new_with(int ini_size); // Crea el vector con tamaño inicial
void vector_free(vector* v); // Eliminar el vector
int vector_size(vector* v); // Obtener el tamaño actual
int vector_isfull(vector* v); // Devuelve 0 si no está lleno
int vector_isempty(vector* v); // Devuelve 0 si no está vacío
void* vector_get(vector* v, int index); // Obtener el elemento de una posición
void* vector_set(vector* v, int index, void* value);// Reemplazar
int vector_add(vector* v, void* value);// Agregar un elemento al final
int vector_insert(vector* v, int index, void* value); // insertar un elemento
void* vector_remove(vector* v, int index); // Remover un elemento

#endif