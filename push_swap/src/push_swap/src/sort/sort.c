#include "../../inc/push_swap.h"

static void		shift_all_without_three(t_stack *a, t_stack *b)
{
	int			begin_size;

	begin_size = a->size;
	while (a->size > 3)
	{
		if (stack_top(a)->order_idx == 0 ||
		stack_top(a)->order_idx == begin_size - 1 ||
		stack_top(a)->order_idx == begin_size / 2)
		{
			stack_rotate(a);
			ft_printf("ra\n");
		}
		else
		{
			stack_shift(b, a);
			ft_printf("pb\n");
		}	
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
	else if (((elem_with_min_operations->appropriate_deep == -(a->size / 2) && a->size % 2 == 1) ||
	elem_with_min_operations->appropriate_deep < 0) &&
	elem_with_min_operations->self_deep < 0)
		handler6(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep < 0 &&
	elem_with_min_operations->self_deep >= 0)
		handler7(a, b, elem_with_min_operations);
}

static void		elements_return(t_stack *a)
{
	t_node		*iter;

	iter = a->barrier->prev;
	while (iter->order_idx != 0)
	{
		stack_reverse_rotate(a);
		ft_printf("rra\n");
		iter = a->barrier->prev;
	}
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
