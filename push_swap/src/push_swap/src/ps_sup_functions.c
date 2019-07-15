/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sup_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:06:53 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 10:31:16 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		deep_set(t_stack *s)
{
	int		i;
	t_node	*iter;

	i = -1;
	iter = s->barrier->prev;
	while (++i < s->size)
	{
		if (i <= s->size / 2)
			iter->self_deep = i;
		else
			iter->self_deep = -(s->size - i);
		iter = iter->prev;
	}
}

t_node		*get_first_idx_node(t_stack *s)
{
	t_node	*iter;

	iter = s->barrier->prev;
	while (iter->order_idx != 0)
		iter = iter->prev;
	return (iter);
}

void		come_back(t_stack *s)
{
	t_node	*iter;

	iter = s->barrier->prev;
	while (iter->order_idx != 0)
	{
		stack_rotate(s);
		ft_printf("ra\n");
		iter = s->barrier->prev;
	}
}

void		come_back_rev(t_stack *s)
{
	t_node	*iter;

	iter = s->barrier->prev;
	while (iter->order_idx != 0)
	{
		stack_reverse_rotate(s);
		ft_printf("rra\n");
		iter = s->barrier->prev;
	}
}
