#include "../inc/stack.h"

int         stack_is_sort(t_stack *s)
{
	int     i;
	t_node  *iter;

	i = -1;
	iter = s->barrier->prev;
	while (++i < s->size - 1)
	{
		if (iter->value > iter->prev->value)
			return (0);
	}
	return (1);
}
