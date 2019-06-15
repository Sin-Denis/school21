#include "checker.h"

void		operations_handler(t_stack *a, t_stack *b, char *operation)
{
	if (ft_strcmp("pa", operation) == 0)
		stack_shift(a, b);
	else if (ft_strcmp("pb", operation) == 0)
		stack_shift(b, a);
	else if (ft_strcmp("sa", operation) == 0)
		stack_swap(a);
	else if (ft_strcmp("sb", operation) == 0)
		stack_swap(b);
	else if (ft_strcmp("ss", operation) == 0)
		stack_simultaneous_swap(a, b);
	else if (ft_strcmp("ra", operation) == 0)
		stack_rotate(a);
	else if (ft_strcmp("rb", operation) == 0)
		stack_rotate(b);
	else if (ft_strcmp("rr", operation) == 0)
		stack_simultaneous_rotate(a, b);
	else if (ft_strcmp("rra", operation) == 0)
		stack_reverse_rotate(a);
	else if (ft_strcmp("rrb", operation) == 0)
		stack_reverse_rotate(b);
	else if (ft_strcmp("rrr", operation) == 0)
		stack_simultaneous_reverse_rotate(a, b);
}

void		state_print(t_stack *a, t_stack *b)
{
	ft_printf("STACK A\n");
	stack_print(a);
	ft_printf("\nSTACK B\n");
	stack_print(b);
}

void		mode_debug(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = NULL;
	stack_print(a);
	while (get_next_line(0, &operation) != 0)
	{
		operations_handler(a, b, operation);
		state_print(a, b);
	}
	ft_strdel(&operation);
}
