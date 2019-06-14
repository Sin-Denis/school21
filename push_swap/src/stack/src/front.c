#include "../inc/stack.h"

t_node			*stack_front(t_stack *s)
{
	return (s->barrier->next);
}
