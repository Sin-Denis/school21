/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:18:13 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 17:33:59 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	common_ops_handler(t_stack *a, t_stack *b, int common_ops)
{
	int		i;

	i = -1;
	while (++i < common_ops)
	{
		stack_simultaneous_reverse_rotate(a, b);
		ft_printf("rrr\n");
	}
}

static void	single_ops_handler(t_stack *s, int single_ops, char stack_id)
{
	int		i;

	i = -1;
	while (++i < single_ops)
	{
		stack_reverse_rotate(s);
		ft_printf("rr%c\n", stack_id);
	}
}

void		handler6(t_stack *a, t_stack *b, t_node *node)
{
	int		common_ops;
	int		single_ops;

	common_ops = ft_min(ft_abs(node->appropriate_deep),
						ft_abs(node->self_deep));
	single_ops = ft_abs(ft_abs(node->appropriate_deep) -
						ft_abs(node->self_deep));
	common_ops_handler(a, b, common_ops);
	if (ft_abs(node->appropriate_deep) > ft_abs(node->self_deep))
		single_ops_handler(a, single_ops, 'a');
	else
		single_ops_handler(b, single_ops, 'b');
	stack_shift(a, b);
	stack_rotate(a);
	ft_printf("pa\nra\n");
}
