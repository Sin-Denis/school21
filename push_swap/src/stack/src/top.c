#include "../inc/stack.h"

t_node			*stack_top(t_stack *s)
{
	return (s->barrier->prev);
}
