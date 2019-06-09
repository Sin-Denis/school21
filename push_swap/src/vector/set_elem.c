#include "vector.h"

void    vector_set_elem(t_vector *v, int idx, vector_type val)
{
    v->data[idx] = val;
}
