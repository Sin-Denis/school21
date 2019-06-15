#include "../inc/stack.h"

void		stack_print(t_stack *s)
{
	int		i;
	t_node	*iter;

	i = -1;
	iter = s->barrier->prev;
	while (++i < s->size)
	{
		ft_printf("%d\n", iter->value);
		iter = iter->prev;
	}
}
