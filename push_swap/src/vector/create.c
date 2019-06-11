#include "vector.h"

t_vector		*vector_create(int size)
{
	int			i;
	t_vector	*v;

	i = 0;
	v = (t_vector *)malloc(sizeof(t_vector));
	if (size == 0)
	{
		v->data = (vector_type *)malloc(sizeof(vector_type) * 10);
		v->size = 0;
		v->capacity = 10;
	}
	else
	{
		v->data = (vector_type *)malloc(sizeof(vector_type) * size * INCREASE_SIZE);
		v->size = size;
		v->capacity = size * INCREASE_SIZE;
	}
	while (i < size)
	{
		v->data[i] = 0;
		++i;
	}
	return (v);
}
