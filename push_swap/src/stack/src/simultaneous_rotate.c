#include "../inc/stack.h"

void			stack_simultaneous_rotate(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
}
