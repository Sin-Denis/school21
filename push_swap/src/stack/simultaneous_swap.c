#include "stack.h"

void			stack_simultaneous_swap(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
}
