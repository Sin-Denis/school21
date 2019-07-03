/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:40:30 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/03 12:22:07 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	common_ops_handler(t_stack *a, t_stack *b, int common_ops)
{
	int i;

	i = -1;
	while (++i < common_ops)
	{
		stack_simultaneous_rotate(a, b);
		ft_printf("rr\n");
	}
}

static void	single_ops_handler(t_stack *s, int single_ops, char stack_id)
{
	int i;

	i = -1;
	while (++i < single_ops)
	{
		stack_rotate(s);
		ft_printf("r%c\n", stack_id);
	}
}

static void	stack_a_ops_handler(t_stack *a, t_stack *b, int stack_a_ops)
{
	int i;

	i = -1;
	stack_shift(a, b);
	stack_swap(a);
	ft_printf("pa\nsa\n");
	while (++i < stack_a_ops)
	{
		stack_reverse_rotate(a);
		ft_printf("rra\n");
	}
}

void	handler4(t_stack *a, t_stack *b, t_node *node)
{
    int common_ops;
	int single_ops;
	int	stack_a_ops;

	common_ops = ft_min(ft_abs(node->appropriate_deep) - 1, node->self_deep);
	single_ops = ft_abs(ft_abs(node->appropriate_deep) - 1 - node->self_deep);
	stack_a_ops = ft_abs(node->appropriate_deep) - 1;
	common_ops_handler(a, b, common_ops);
	if (ft_abs(node->appropriate_deep) - 1 > node->self_deep)
		single_ops_handler(a, single_ops, 'a');
	else 
		single_ops_handler(b, single_ops, 'b');
	stack_a_ops_handler(a, b, stack_a_ops);
}