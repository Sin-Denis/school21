/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:47:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:01:47 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	handler1(t_stack *a, t_stack *b, t_node *node)
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
	stack_rotate(a);
	ft_printf("pa\nra\n");
}
