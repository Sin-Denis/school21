#include "../inc/stack.h"

void		stack_clean(t_stack *s)
{
	int		i;
	int		stack_size;

	i = -1;
	stack_size = s->size;
	while (++i < stack_size)
		stack_pop_back(s);
}
