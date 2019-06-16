#include "../inc/stack.h"

int	stack_simultaneous_rotate(t_stack *a, t_stack *b)
{
	if (stack_rotate(a) == -1 || stack_rotate(b) == -1)
		return (-1);
	return (0);
}
