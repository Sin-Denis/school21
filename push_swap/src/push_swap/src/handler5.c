/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:03:12 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:05:58 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		stack_a_ops_handler(t_stack *a, int stack_a_ops)
{
	int			i;

	i = 0;
	while (++i < stack_a_ops)
	{
		stack_rotate(a);
		ft_printf("ra\n");
	}
}

static void		stack_b_ops_handler(t_stack *b, int stack_b_ops)
{
	int			i;

	i = -1;
	while (++i < stack_b_ops)
	{
		stack_reverse_rotate(b);
		ft_printf("rrb\n");
	}
}

void			handler5(t_stack *a, t_stack *b, t_node *node)
{
	stack_a_ops_handler(a, node->appropriate_deep);
	stack_b_ops_handler(b, ft_abs(node->self_deep));
	stack_shift(a, b);
	stack_swap(a);
	ft_printf("pa\nsa\n");
}
