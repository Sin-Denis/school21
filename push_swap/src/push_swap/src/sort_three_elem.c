/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:37:42 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 10:30:42 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		get_min_idx(t_stack *s)
{
	int			min_idx;
	int			i;
	t_node		*iter;

	min_idx = s->barrier->prev->order_idx;
	iter = s->barrier->prev->prev;
	i = 0;
	while (++i < s->size)
	{
		if (iter->order_idx < min_idx)
			min_idx = iter->order_idx;
		iter = iter->prev;
	}
	return (min_idx);
}

static void		sort_three_elem_sup_func1(t_stack *a)
{
	stack_rotate(a);
	stack_swap(a);
	ft_printf("ra\nsa\n");
}

static void		sort_three_elem_sup_func2(t_stack *a)
{
	stack_reverse_rotate(a);
	stack_swap(a);
	ft_printf("rra\nsa\n");
}

static void		sort_three_elem_body(t_stack *a, t_node *n1,
									t_node *n2, t_node *n3)
{
	int			min_idx;

	min_idx = get_min_idx(a);
	if (n1->order_idx == min_idx && n2->order_idx > n3->order_idx)
		sort_three_elem_sup_func2(a);
	else if (n2->order_idx == min_idx && n1->order_idx < n3->order_idx)
	{
		stack_swap(a);
		ft_printf("sa\n");
	}
	else if (n2->order_idx == min_idx)
	{
		stack_rotate(a);
		ft_printf("ra\n");
	}
	else if (n3->order_idx == min_idx && n1->order_idx < n2->order_idx)
	{
		stack_reverse_rotate(a);
		ft_printf("rra\n");
	}
	else if (n3->order_idx == min_idx)
		sort_three_elem_sup_func1(a);
}

void			sort_three_elem(t_stack *a)
{
	if (a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (stack_top(a)->order_idx != 0)
		{
			stack_swap(a);
			ft_printf("sa\n");
		}
		return ;
	}
	sort_three_elem_body(
		a,
		a->barrier->prev,
		a->barrier->prev->prev,
		a->barrier->prev->prev->prev);
}
