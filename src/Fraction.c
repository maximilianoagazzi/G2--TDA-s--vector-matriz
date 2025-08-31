#include <stdio.h>
#include <stdlib.h>
#define FRACTION_H_EXPORT
#include "Fraction.h"

struct fraction {
    int num;
    int den;
};

fraction *fraction_new (int num, int den) 
{
    fraction *f = malloc(sizeof(fraction));
    if (den == 0) {
        printf("Error: Denominator cannot be zero.\n");
        free(f);
        return NULL;
    }
    (*f).num = num;
    (*f).den = den;
    fraction_sgn (f);
    fraction_simplify(f);
    return f;
}

void fraction_print (fraction* f)
{
    printf("%d/%d\n", (*f).num, (*f).den);
}

void fraction_destroy (fraction* f)
{
    free(f);
}

int fraction_get_num (fraction* f)
{
    return (*f).num;
}

int fraction_get_den (fraction* f)
{
    return (*f).den;
}

fraction* fraction_add (fraction* f1, fraction* f2)
{
    fraction *result;
    result = malloc(sizeof(fraction));
    (*result).num = (*f1).num *(*f2).den + (*f2).num * (*f1).den;
    (*result).den = (*f1).den * (*f2).den;
    fraction_simplify(result);
    fraction_sgn (result);
    return result;
}

fraction* fraction_sub (fraction* f1, fraction* f2)
{
    fraction *result;
    result = malloc(sizeof(fraction));
    (*result).num = (*f1).num *(*f2).den - (*f2).num * (*f1).den;
    (*result).den = (*f1).den * (*f2).den;
    fraction_simplify(result);
    fraction_sgn (result);
    return result;
}

fraction* fraction_mul (fraction* f1, fraction* f2)
{
    fraction *result;
    result = malloc(sizeof(fraction));
    (*result).num = (*f1).num * (*f2).num;
    (*result).den = (*f1).den * (*f2).den;
    fraction_simplify(result);
    fraction_sgn (result);
    return result;
}

fraction* fraction_div (fraction* f1, fraction* f2)
{
    fraction *result;
    result = malloc(sizeof(fraction));
    (*result).num = (*f1).num * (*f2).den;
    (*result).den = (*f1).den * (*f2).num;
    fraction_simplify(result);
    fraction_sgn (result);
    return result;
}

void fraction_simplify (fraction* f)
{
    int a = (*f).num;
    int b = (*f).den;
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    (*f).num /= a;
    (*f).den /= a;
}

int fraction_cmp (fraction* f1, fraction* f2)
{
    float val1 = (float)(*f1).num / (*f1).den;
    float val2 = (float)(*f2).num / (*f2).den;
    if (val1 == val2) {
        return 0;
    } else if (val1 < val2) {
        return -1;
    } else if (val1 > val2) {
        return 1;
    }
}

void fraction_sgn (fraction* f)
{
    if ((*f).den < 0) {
        (*f).num = -(*f).num;
        (*f).den = -(*f).den;
    }
}