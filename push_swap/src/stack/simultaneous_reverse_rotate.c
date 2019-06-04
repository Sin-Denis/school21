#include "stack.h"

void			stack_simultaneous_reverse_rotate(t_stack *a, t_stack *b)
{
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
}
