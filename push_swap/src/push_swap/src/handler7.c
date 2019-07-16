/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:03:12 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 09:03:57 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		stack_a_ops_handler(t_stack *a, int stack_a_ops)
{
	int			i;

	i = -1;
	while (++i < stack_a_ops)
	{
		stack_reverse_rotate(a);
		ft_printf("rra\n");
	}
}

static void		stack_b_ops_handler(t_stack *b, int stack_b_ops)
{
	int			i;

	i = -1;
	while (++i < stack_b_ops)
	{
		stack_rotate(b);
		ft_printf("rb\n");
	}
}

void			handler7(t_stack *a, t_stack *b, t_node *node)
{
	stack_a_ops_handler(a, ft_abs(node->appropriate_deep));
	stack_b_ops_handler(b, ft_abs(node->self_deep));
	stack_shift(a, b);
	ft_printf("pa\n");
}
