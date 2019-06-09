#include "vector.h"

void	vector_print(t_vector *v)
{
	int i;
	int val;

	i = -1;
	while (++i < vector_length(v))
		if (i == vector_length(v) - 1)
			printf("%d\n", vector_get_elem(v, i));
		else
			printf("%d ", vector_get_elem(v, i));
}
