/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:52:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:03:06 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	handler2(t_stack *a, t_stack *b, t_node *node)
{
	int	deep;

	deep = node->self_deep;
	while (deep > 0)
	{
		stack_rotate(b);
		ft_printf("rb\n");
		deep--;
	}
	while (deep < 0)
	{
		stack_reverse_rotate(b);
		ft_printf("rrb\n");
		deep++;
	}
	stack_shift(a, b);
	ft_printf("pa\n");
}
