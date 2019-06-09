#include <stdio.h>
#include "vector.h"

int main(void)
{
    t_vector *v;

    v = vector_create(4);
    printf("vector_size: %d\n", vector_length(v));
    vector_set_elem(v, 2, 4);
    vector_print(v);
    vector_resize(v, 10);
    vector_print(v);
    vector_destroy(&v);
    return (0);
}
