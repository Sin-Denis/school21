#include "../include/vector.h"

void	vector_print(t_vector *v)
{
	int	i;
	
	if (v == NULL)
		return ;
	i = -1;
	while (++i < v->size)
		ft_printf("%d ", v->data[i]);
}
