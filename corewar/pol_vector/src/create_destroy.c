//
// Created by Jessie Blue dartwing on 23/08/2019.
//

#include "../include/pol_vector.h"

t_pol_vector	*pol_vector_create(size_t size, size_t obj_size)
{
	t_pol_vector	*v;

	v = (t_pol_vector *)malloc(sizeof(t_pol_vector));
	v->_size = size;
	v->_cap = (size == 0) ? 10 : size * 2;
	v->_data = malloc(obj_size * v->_cap);
	return (v);
}

void	pol_vector_destroy(t_pol_vector **v, void (*obj_destroy)(void *))
{
	size_t	i;

	i = 0;
	while (i < (*v)->_size)
	{
		(*obj_destroy)((unsigned char *)(*v)->_data + i * (*v)->_obj_size);
		++i;
	}
	free((*v)->_data);
	*v = NULL;
}
