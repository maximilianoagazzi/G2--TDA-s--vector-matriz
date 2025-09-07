#include <stdlib.h>
#define MATRIX_H_EXPORT
#include "matrix.h"

typedef struct matrix {
    void** data; // Puntero a un array de punteros a void
    int size; // Número actual de elementos de la matiz de forma unidimensional
    int rows;    // Número de filas de la matriz
    int columns;  //Número de columnas de la matriz
} matrix;

matrix* matrix_new(int rows, int columns)
{
    matrix *m = (matrix *)malloc(sizeof(matrix));
    if (m == NULL) {
        return NULL;
    }
    if (rows <= 0 || columns <= 0) {
        return NULL;
    }
    m->data = NULL;
    m->rows = rows;
    m->columns = columns;
    m->size = rows*columns;
    m->data = (void **)malloc((m->rows) * (m->columns) * sizeof(void *));
    if (m->data == NULL) {
        free(m);
        return NULL;
    }
    return m;
}

void matrix_free(matrix* m)
{
    if (m != NULL) {
        free(m->data);
        free(m);
    }
    return;
}

int matrix_rows(matrix* m)
{
    if (m != NULL) {
        return m->rows;
    }
    return -1; // Indica error
}

int matrix_columns(matrix* m)
{
    if (m != NULL) {
        return m->columns;
    }
    return -1; // Indica error
}

void* matrix_get(matrix* m, int row, int column)
{
    if (m != NULL && row >= 0 && column >= 0 && row < m->rows && column < m->columns) {
        return m->data[row*(m->columns) + column];
    }
    return NULL; // Indica error
}

void* matrix_set(matrix* m, int row, int column, void* value)
{
    if (m != NULL && row >= 0 && column >= 0 && row < m->rows && column < m->columns) {
        void *old_value = m->data[row*(m->columns) + column];
        m->data[row*(m->columns) + column] = value;
        return old_value;
    }
    return NULL; // Indica error
}