#include <stdio.h>
#include "vector.h"

int main(void)
{
    t_vector *v;
    v = vector_create(0);
    vector_push_back(v, 3);
    vector_push_back(v, -1);
    vector_push_back(v, 6);
    vector_push_back(v, 0);
    vector_quick_sort(v);
    vector_print(v);
    vector_destroy(&v);
    return (0);
}
