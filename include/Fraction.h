#ifdef FRACTION_H_EXPORT
#define FRACTION_API __declspec(dllexport)
#else
#define FRACTION_API __declspec(dllimport)
#endif

typedef struct fraction fraction;

FRACTION_API fraction *fraction_new (int num, int den);
FRACTION_API void fraction_print (fraction* f);
FRACTION_API void fraction_destroy (fraction* f);
FRACTION_API int fraction_get_num (fraction* f);
FRACTION_API int fraction_get_den (fraction* f);
FRACTION_API fraction* fraction_add (fraction* f1, fraction* f2);
FRACTION_API fraction* fraction_sub (fraction* f1, fraction* f2);
FRACTION_API fraction* fraction_mul (fraction* f1, fraction* f2);
FRACTION_API fraction* fraction_div (fraction* f1, fraction* f2);
FRACTION_API void fraction_simplify (fraction* f);
FRACTION_API int fraction_cmp (fraction* f1, fraction* f2);
FRACTION_API void fraction_sgn (fraction* f);