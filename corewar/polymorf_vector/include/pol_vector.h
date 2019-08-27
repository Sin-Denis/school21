#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_pol_vector
{
	void		*_data;
	void		(*_obj_destroy)(void *);
	size_t		_obj_size;
	size_t		_size;
	size_t		_cap;
}				t_pol_vector;

t_pol_vector	*pol_vector_create(size_t size, size_t obj_size, void (*obj_destroy)(void *));
void			pol_vector_destroy(t_pol_vector **v);
void			pol_vector_push_back(t_pol_vector *v, void *key);
size_t			pol_vector_size(t_pol_vector *v);
void			*pol_vector_at(t_pol_vector *v, size_t idx);
void			pol_vector_print(t_pol_vector *v, void (*obj_print)(void *obj));
