#include "vector.h"

static int		abs_val(int num)
{
	return (num < 0) ? -num : num;
}

static int		min_val(int l, int r)
{
	return (l < r) ? l : r;
}

void			vector_resize(t_vector *v, int size)
{
	int			i;
	int			data_size;
	vector_type	*new_data;

	i = -1;
	data_size = min_val(size, vector_length(v));
	new_data = (vector_type *)malloc(sizeof(vector_type) * size * INCREASE_SIZE);
	while (++i < data_size)
		new_data[i] = vector_get_elem(v, i);
	while (i < size)
		new_data[i++] = 0;
	free(v->data);
	v->data = new_data;
	v->size = size;
	v->capacity = size * INCREASE_SIZE;
}
