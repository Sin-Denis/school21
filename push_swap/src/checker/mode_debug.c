#include "checker.h"

void		error_handler_unary(t_stack *a, t_stack *b, int (*f)(t_stack *))
{
	if ((*f)(a) == -1)
	{
		stack_destroy(&a);
		stack_destroy(&b);
		write(0, "Error\n", 6);
		exit(1);
	}
}

void		error_handler_binary(t_stack *a, t_stack *b, int (*f)(t_stack *, t_stack *))
{
	if ((*f)(a, b) == -1)
	{
		stack_destroy(&a);
		stack_destroy(&b);
		write(0, "Error\n", 6);
		exit(1);
	}
}

void	operations_handler(t_stack *a, t_stack *b, char *operation)
{
	if (ft_strcmp("pa", operation) == 0)
		error_handler_binary(a, b, stack_shift);
	else if (ft_strcmp("pb", operation) == 0)
		error_handler_binary(b, a, stack_shift);
	else if (ft_strcmp("sa", operation) == 0)
		error_handler_unary(a, b, stack_swap);
	else if (ft_strcmp("sb", operation) == 0)
		error_handler_unary(b, a, stack_swap);
	else if (ft_strcmp("ss", operation) == 0)
		error_handler_binary(a, b, stack_simultaneous_swap);
	else if (ft_strcmp("ra", operation) == 0)
		error_handler_unary(a, b, stack_rotate);
	else if (ft_strcmp("rb", operation) == 0)
		error_handler_unary(b, a, stack_rotate);
	else if (ft_strcmp("rr", operation) == 0)
		error_handler_binary(a, b, stack_simultaneous_rotate);
	else if (ft_strcmp("rra", operation) == 0)
		error_handler_unary(a, b, stack_reverse_rotate);
	else if (ft_strcmp("rrb", operation) == 0)
		error_handler_unary(b, a, stack_reverse_rotate);
	else if (ft_strcmp("rrr", operation) == 0)
		error_handler_binary(a, b, stack_simultaneous_reverse_rotate);
}

static void	table_print(t_stack *a, t_stack *b, int size_a, int size_b)
{
	t_node	*iter_a;
	t_node	*iter_b;

	iter_a = a->barrier->prev;
	iter_b = b->barrier->prev;
	while (size_a > 0 || size_b > 0)
	{
		if (size_a == 0)
			ft_printf("|              |||  %-10d  |\n", iter_b->value);
		else if (size_b == 0)
			ft_printf("|  %-10d  |||              |\n", iter_a->value);
		else
			ft_printf("|  %-10d  |||  %-10d  |\n", iter_a->value, iter_b->value);
		if (size_a != 0)
		{
			iter_a = iter_a->prev;
			size_a--;
		}
		if (size_b != 0)
		{
			iter_b = iter_b->prev;
			size_b--;
		}
	}
}

void		state_print(t_stack *a, t_stack *b)
{
	int 	size_a;
	int 	size_b;

	size_a = a->size;
	size_b = b->size;
	ft_printf("---------------------------------\n");
	ft_printf("|    STACK A   |||    STACK B   |\n");
	ft_printf("---------------------------------\n");
	table_print(a, b, size_a, size_b);

}

void		mode_debug(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = NULL;
	state_print(a, b);
	while (get_next_line(0, &operation) != 0)
	{
		operations_handler(a, b, operation);
		state_print(a, b);
	}
	ft_strdel(&operation);
}
