#include "../inc/vector.h"

vector_type	vector_get_elem(t_vector *v, int idx)
{
	return (v->data[idx]);
}
