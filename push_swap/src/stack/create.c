#include "stack.h"

t_stack			*stack_create(void)
{
	t_stack		*s;

	if ((s = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit(1);
    s->barrier = node_create(0);
	s->size = 0;
	return (s);
}
