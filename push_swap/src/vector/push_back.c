#include "vector.h"

void	vector_push_back(t_vector *v, vector_type val)
{
	if (v->size == v->capacity)
		vector_resize(v, v->size);
	vector_set_elem(v, v->size, val);
	v->size++;
}
