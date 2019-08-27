#include "vector.h"

t_vector	*pol_vector_create(size_t size, size_t obj_size, void (*obj_destroy)(void *))
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	v->_obj_destroy = obj_destroy;
	v->_size = size;
	v->_obj_size = obj_size;
	v->_cap = (size == 0) ? 10 : size * 2;
	v->_data = malloc(v->_cap * obj_size);
	return (v);
}

void	pol_vectordestroy(t_vector **v)
{
	size_t	i;

	i = 0;
	while (i < (*v)->_size)
	{
		(*(*v)->_obj_destroy)(((unsigned char *)(*v)->_data) + i * (*v)->_obj_size);
		++i;
	}
	free((*v)->_data);
	*v = NULL;
}

void	pol_vector_push_back(t_vector *v, void *key)
{
	size_t i;

	i = 0;
	if (v->_size == v->_cap)
	{
		v->_data = realloc(v->_data, v->_size * 2 * v->_obj_size);
		if (v->_data == NULL) {
			perror("Memory end\n");
			exit(1);
		}
	}
	memcpy(((unsigned char *)v->_data) + v->_obj_size * v->_size, key, v->_obj_size);
	++v->_size;
}

size_t	pol_vector_size(t_vector *v)
{
	return v->_size;
}

void	pol_vector_set(t_vector *v, size_t idx, void *key)
{
	memcpy((unsigned char *)v->_data + v->_obj_size * idx, key, v->_obj_size);
}

void	*pol_vector_at(t_vector *v, size_t idx)
{
	return (unsigned char *)v->_data + idx * v->_obj_size;
}

void	pol_vector_vector_print(t_vector *v, void (*obj_print)(void *obj))
{
	size_t i;

	i = 0;
	while (i < v->_size)
	{
		(*obj_print)(((unsigned char *)v->_data) + i * v->_obj_size);
		++i;
	}
}
