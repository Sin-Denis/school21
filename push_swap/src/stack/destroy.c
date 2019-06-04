#include "stack.h"

void			stack_destroy(t_stack **s)
{
	int			i;
	int			stack_size;

	i = -1;
	stack_size = (*s)->size;
	while (++i < stack_size)
		stack_pop_front(*s);
	node_destroy(&(*s)->barrier);
	free(*s);
	*s = NULL;
}
