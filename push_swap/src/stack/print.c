#include "stack.h"

void				stack_print(t_stack *s)
{
	int				i;
	t_node			*itter;

	i = 0;
	itter = s->barrier->next;
	while (i < s->size)
	{
		printf("%d ", itter->value);
		itter = itter->next;
		++i;
	}
}
