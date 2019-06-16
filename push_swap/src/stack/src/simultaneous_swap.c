#include "../inc/stack.h"

int	stack_simultaneous_swap(t_stack *a, t_stack *b)
{
	if (stack_swap(a) == -1 || stack_swap(b) == -1)
		return (-1);
	return (0);
}
