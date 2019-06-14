#ifndef VECTOR_H_
#define VECTOR_H_

#define INCREASE_SIZE 2

#include "../Libftprintf/libftprinf.h"

typedef int vector_type;

typedef struct	s_vector
{
	vector_type	*data;
	int			size;
	int			capacity;
}				t_vector;

t_vector		*vector_create(int size);
void			vector_destroy(t_vector **v);
void			vector_resize(t_vector *v, int size);
vector_type		vector_get_elem(t_vector *v, int idx);
void			vector_set_elem(t_vector *v, int idx, vector_type val);
void			vector_push_back(t_vector *v, vector_type val);
int				vector_length(t_vector *v);
void			vector_print(t_vector *v);
void			vector_quick_sort(t_vector *v);

#endif
