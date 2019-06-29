#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
    stack_destroy(&a);
	stack_destroy(&b);
	write(2, "Error\n", 6);
	exit(1);
}
