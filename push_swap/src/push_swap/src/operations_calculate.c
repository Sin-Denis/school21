/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_calculate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:37:37 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 17:34:52 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*get_near_elem(t_stack *s, int order_idx)
{
	t_node		*iter;
	t_node		*near_elem;
	int			i;

	iter = s->barrier->prev;
	near_elem = NULL;
	i = -1;
	while (++i < s->size)
	{
		if (iter->order_idx > order_idx)
		{
			near_elem = iter;
			iter = iter->prev;
			break ;
		}
		iter = iter->prev;
	}
	while (++i < s->size)
	{
		if (iter->order_idx > order_idx &&
		iter->order_idx < near_elem->order_idx)
			near_elem = iter;
		iter = iter->prev;
	}
	return (near_elem);
}

static void		operations_calculate_item(t_stack *a, t_node *iter_b)
{
	t_node		*iter_a;

	iter_a = get_near_elem(a, iter_b->order_idx);
	if (iter_a == NULL)
		iter_b->operations_amount = 2 + ft_abs(iter_b->self_deep);
	else if (iter_a->self_deep == 0)
		iter_b->operations_amount = 1 + ft_abs(iter_b->self_deep);
	else if (iter_a->self_deep == -(a->size / 2) && a->size % 2 == 1 &&
	iter_b->self_deep >= 0)
		iter_b->operations_amount = ft_max(ft_abs(iter_a->self_deep),
											ft_abs(iter_b->self_deep)) + 2;
	else if (iter_a->self_deep > 0 && iter_b->self_deep >= 0)
		iter_b->operations_amount = ft_max(ft_abs(iter_b->self_deep),
											ft_abs(iter_a->self_deep) - 1) + 2;
	else if (iter_a->self_deep > 0 && iter_b->self_deep < 0)
		iter_b->operations_amount = iter_a->self_deep - 1 +
		ft_abs(iter_b->self_deep) + 2;
	else if (((iter_a->self_deep == -(a->size / 2) && a->size % 2 == 1) ||
	iter_a->self_deep < 0) && iter_b->self_deep < 0)
		iter_b->operations_amount = ft_max(ft_abs(iter_a->self_deep),
											ft_abs(iter_b->self_deep)) + 2;
	else if (iter_a->self_deep < 0 && iter_b->self_deep > 0)
		iter_b->operations_amount = ft_abs(iter_a->self_deep) +
									ft_abs(iter_b->self_deep) + 2;
	iter_b->appropriate_deep = (iter_a == NULL) ? a->size : iter_a->self_deep;
}

void			operations_calculate(t_stack *a, t_stack *b)
{
	int			i;
	t_node		*iter_b;

	i = -1;
	iter_b = b->barrier->prev;
	deep_set(a);
	deep_set(b);
	while (++i < b->size)
	{
		operations_calculate_item(a, iter_b);
		iter_b = iter_b->prev;
	}
}
