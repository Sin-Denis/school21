#include "push_swap.h"

void	shift_all_without_three(t_stack *a, t_stack *b)
{
	int begin_size;

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

void		operations_calculate(t_stack *a, t_stack *b)
{
	int		i;
	int 	j;
	t_node	*iter_a;
	t_node	*iter_b;

	i = -1;
	iter_b = b->barrier->prev;
	deep_set(a);
	deep_set(b);
	while (++i < b->size)
	{
		j = -1;
		iter_a = a->barrier->prev;
		while (++j < a->size && iter_a->order_idx < iter_b->order_idx)
			iter_a = iter_a->prev;
		if (j == a->size)
			iter_b->operations_amount = 2 + ft_abs(iter_b->self_deep);
		else if (j == 0)
			iter_b->operations_amount = 1 + ft_abs(iter_b->self_deep);
		else if (j == a->size / 2 + 1 && a->size % 2 == 1 && iter_b->self_deep >= 0)
			iter_b->operations_amount = ft_max(ft_abs(iter_a->self_deep),
			ft_abs(iter_b->self_deep)) + 2 + ft_abs(iter_a->self_deep);
		else if (j <= a->size / 2 && iter_b->self_deep >= 0)
			iter_b->operations_amount = ft_max(ft_abs(iter_b->self_deep),
			ft_abs(iter_a->self_deep) - 1) + 2 + ft_abs(iter_a->self_deep) - 1;
		else if (j <= a->size / 2 && iter_b->self_deep < 0)
			iter_b->operations_amount = (iter_a->self_deep - 1) * 2 +ft_abs(iter_b->self_deep) + 2;
		else if (((j == a->size / 2 + 1 && a->size % 2 == 1) || j > a->size / 2) &&
			iter_b->self_deep < 0)
			iter_b->operations_amount = ft_max(ft_abs(iter_a->self_deep),
			ft_abs(iter_b->self_deep)) + ft_abs(iter_a->self_deep) + 2;
		else if (j > a->size / 2 && iter_b->self_deep > 0)
			iter_b->operations_amount = ft_abs(iter_a->self_deep) * 2 +
			ft_abs(iter_b->self_deep) + 2;
		iter_b->appropriate_deep = (j == a->size) ? a->size : iter_a->self_deep;
		iter_b = iter_b->prev;
	}
}

t_node		*get_elem_with_min_operations(t_stack *s)
{
	int		i;
	t_node	*min_node;
	t_node	*iter;

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

void		choose_elem(t_stack *a, t_stack *b)
{
	t_node	*elem_with_min_operations;

	elem_with_min_operations = get_elem_with_min_operations(b);
	if (elem_with_min_operations->appropriate_deep == a->size)
		handler1(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep == 0)
		handler2(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep == a->size / 2 + 1 &&
	a->size % 2 == 1 && elem_with_min_operations->self_deep >= 0)
		handler3(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep <= a->size / 2 &&
	elem_with_min_operations->self_deep >= 0)
		handler4(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep <= a->size / 2 &&
	elem_with_min_operations->self_deep < 0)
		handler5(a, b, elem_with_min_operations);
	else if (((elem_with_min_operations->appropriate_deep == a->size / 2 + 1 && a->size % 2 == 1) ||
	elem_with_min_operations->appropriate_deep > a->size / 2) &&
	elem_with_min_operations->self_deep < 0)
		handler6(a, b, elem_with_min_operations);
	else if (elem_with_min_operations->appropriate_deep > a->size / 2 &&
	elem_with_min_operations->self_deep >= 0)
		handler7(a, b, elem_with_min_operations);
}

void	state_print(t_stack *a, t_stack *b)
{
	int		i;
	t_node	*iter;

	i = -1;
	iter = a->barrier->prev;
	while (++i < a->size)
	{
		ft_printf("Val: %5d, Idx: %3d, Deep: %3d, Amount_oper: %3d, App_deep: %3d\n",
			iter->value,
			iter->order_idx,
			iter->self_deep,
			iter->operations_amount,
			iter->appropriate_deep
		);
		iter = iter->prev;
	}
	ft_printf("\n");
	i = -1;
	iter = b->barrier->prev;
	while (++i < b->size)
	{
		ft_printf("Val: %5d, Idx: %3d, Deep: %3d, Amount_oper: %3d, App_deep: %3d\n",
			iter->value,
			iter->order_idx,
			iter->self_deep,
			iter->operations_amount,
			iter->appropriate_deep
		);
		iter = iter->prev;
	}
	ft_printf("\n");
}

void    sort(t_stack *a, t_stack *b)
{
    shift_all_without_three(a, b);
	sort_three_elem(a);
	operations_calculate(a, b);
    while (!stack_is_empty(b))
    {
        operations_calculate(a, b);
		choose_elem(a, b);
    }
}
