/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:37:45 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 10:26:35 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		shift_all_without_three(t_stack *a, t_stack *b)
{
	int			begin_size;

	begin_size = a->size;
	while (a->size > 3)
	{
		stack_shift(b, a);
		ft_printf("pb\n");
	}
}

static t_node	*get_elem_with_min_operations(t_stack *s)
{
	int			i;
	t_node		*min_node;
	t_node		*iter;

	i = 0;
	min_node = s->barrier->prev;
	iter = s->barrier->prev->prev;
	while (++i < s->size)
	{
		if (iter->operations_amount < min_node->operations_amount)
			min_node = iter;
		iter = iter->prev;
	}
	return (min_node);
}

static void		choose_elem(t_stack *a, t_stack *b)
{
	t_node		*elem_with_min_operations;

	elem_with_min_operations = get_elem_with_min_operations(b);
	if (elem_with_min_operations->appropriate_deep == a->size)
		handler1(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep == 0)
		handler2(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep == -(a->size / 2) &&
	a->size % 2 == 1 && elem_with_min_operations->self_deep >= 0)
		handler3(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep > 0 &&
	elem_with_min_operations->self_deep >= 0)
		handler4(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep > 0 &&
	elem_with_min_operations->self_deep < 0)
		handler5(a, b, elem_with_min_operations);
	else if (((elem_with_min_operations->appropriate_deep == -(a->size / 2) &&
	a->size % 2 == 1) || elem_with_min_operations->appropriate_deep < 0) &&
	elem_with_min_operations->self_deep < 0)
		handler6(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep < 0 &&
	elem_with_min_operations->self_deep >= 0)
		handler7(a, b, elem_with_min_operations);
}

static void		elements_return(t_stack *a)
{
	t_node		*first_idx_node;

	deep_set(a);
	first_idx_node = get_first_idx_node(a);
	if (first_idx_node->self_deep > 0)
		come_back(a);
	else
		come_back_rev(a);
}

void			sort(t_stack *a, t_stack *b)
{
	if (stack_is_sort(a) && stack_is_empty(b))
		return ;
	shift_all_without_three(a, b);
	sort_three_elem(a);
	operations_calculate(a, b);
	while (!stack_is_empty(b))
	{
		operations_calculate(a, b);
		choose_elem(a, b);
	}
	elements_return(a);
}
