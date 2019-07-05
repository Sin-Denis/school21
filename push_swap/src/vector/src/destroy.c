#include "../inc/vector.h"

void	vector_destroy(t_vector **v)
{
	free((*v)->data);
	(*v)->data = NULL;
	free(*v);
	*v = NULL;
}
