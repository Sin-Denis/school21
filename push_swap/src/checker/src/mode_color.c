/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:30:24 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 09:35:55 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static void	table_print_body(int size_a, int size_b,
							t_node *iter_a, t_node *iter_b)
{
	if (size_a == 0 && size_b != 0)
	{
		ft_printf(
			"\033[31;1m|              |||  \033[34;1m%-10d  \033[31;1m|\n",
			iter_b->value);
	}
	else if (size_b == 0 && size_a != 0)
	{
		ft_printf("|  \033[34;1m%-10d  \033[31;1m|||              |\n",
			iter_a->value);
	}
	else
	{
		ft_printf("\033[31;1m|  \033[34;1m%-10d  \033[31;1m|||", iter_a->value);
		ft_printf("  \033[34;1m%-10d  \033[31;1m|\n", iter_b->value);
	}
}

static void	table_print(t_stack *a, t_stack *b, int size_a, int size_b)
{
	t_node	*iter_a;
	t_node	*iter_b;

	iter_a = a->barrier->prev;
	iter_b = b->barrier->prev;
	while (size_a > 0 || size_b > 0)
	{
		table_print_body(size_a, size_b, iter_a, iter_b);
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

static void	state_print(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;

	size_a = a->size;
	size_b = b->size;
	ft_printf("\033[31;1m---------------------------------\n");
	ft_printf("|    \033[32;1mSTACK A\033[31;1m   |||");
	ft_printf("    \033[32;1mSTACK B\033[31;1m   |\n");
	ft_printf("---------------------------------\n");
	table_print(a, b, size_a, size_b);
}

void		mode_color(t_stack *a, t_stack *b)
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
