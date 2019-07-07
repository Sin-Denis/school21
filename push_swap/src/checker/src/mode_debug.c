#include "../inc/checker.h"

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
		if (operation_is_not_exist(operation))
			checker_error_exit(a, b, operation);
		operations_handler(a, b, operation);
		state_print(a, b);
	}
	ft_strdel(&operation);
}
