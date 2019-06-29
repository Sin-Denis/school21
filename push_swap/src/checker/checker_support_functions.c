#include "checker.h"

void	checker_error_exit(t_stack *a, t_stack *b, char *operation)
{
	stack_destroy(&a);
	stack_destroy(&b);
	ft_strdel(&operation);
	write(2, "Error\n", 6);
	exit(1);
}

void		error_handler_unary(t_stack *a, t_stack *b, char *operation, int (*f)(t_stack *))
{
	if ((*f)(a) == -1)
		checker_error_exit(a, b, operation);
}

void		error_handler_binary(t_stack *a, t_stack *b, char *operation, int (*f)(t_stack *, t_stack *))
{
	if ((*f)(a, b) == -1)
		checker_error_exit(a, b, operation);
}

void	operations_handler(t_stack *a, t_stack *b, char *operation)
{
	if (ft_strcmp("pa", operation) == 0)
		error_handler_binary(a, b, operation, stack_shift);
	else if (ft_strcmp("pb", operation) == 0)
		error_handler_binary(b, a, operation, stack_shift);
	else if (ft_strcmp("sa", operation) == 0)
		error_handler_unary(a, b, operation, stack_swap);
	else if (ft_strcmp("sb", operation) == 0)
		error_handler_unary(b, a, operation, stack_swap);
	else if (ft_strcmp("ss", operation) == 0)
		error_handler_binary(a, b, operation, stack_simultaneous_swap);
	else if (ft_strcmp("ra", operation) == 0)
		error_handler_unary(a, b, operation, stack_rotate);
	else if (ft_strcmp("rb", operation) == 0)
		error_handler_unary(b, a, operation, stack_rotate);
	else if (ft_strcmp("rr", operation) == 0)
		error_handler_binary(a, b, operation, stack_simultaneous_rotate);
	else if (ft_strcmp("rra", operation) == 0)
		error_handler_unary(a, b, operation, stack_reverse_rotate);
	else if (ft_strcmp("rrb", operation) == 0)
		error_handler_unary(b, a, operation, stack_reverse_rotate);
	else if (ft_strcmp("rrr", operation) == 0)
		error_handler_binary(a, b, operation, stack_simultaneous_reverse_rotate);
}

int			operation_is_not_exist(char *op)
{
	if (ft_strcmp(op, "pa") == 0 ||
	ft_strcmp(op, "pb") == 0 ||
	ft_strcmp(op, "sa") == 0 ||
	ft_strcmp(op, "sb") == 0 ||
	ft_strcmp(op, "ss") == 0 ||
	ft_strcmp(op, "ra") == 0 ||
	ft_strcmp(op, "rb") == 0 ||
	ft_strcmp(op, "rr") == 0 ||
	ft_strcmp(op, "rra") == 0 ||
	ft_strcmp(op, "rrb") == 0 ||
	ft_strcmp(op, "rrr") == 0)
		return (0);
	return (1);
}