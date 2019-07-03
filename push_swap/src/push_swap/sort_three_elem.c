#include "push_swap.h"

void		sort_three_elem_body(t_stack *a, t_node *n1, t_node *n2, t_node *n3)
{
	if (n1->order_idx == 0 && n2->order_idx > n3->order_idx)
	{
		stack_reverse_rotate(a);
		stack_swap(a);
		ft_printf("rra\nsa\n");
	}
	else if (n2->order_idx == 0 && n1->order_idx < n3->order_idx)
	{
		stack_swap(a);
		ft_printf("sa\n");
	}
	else if (n2->order_idx == 0)
	{
		stack_rotate(a);
		ft_printf("ra\n");
	}
	else if (n3->order_idx == 0 && n1->order_idx < n2->order_idx)
	{
		stack_reverse_rotate(a);
		ft_printf("rra\n");
	}
	else if (n3->order_idx == 0)
	{
		stack_rotate(a);
		stack_swap(a);
		ft_printf("ra\nsa\n");
	}
}

void		sort_three_elem(t_stack *a)
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
			a->barrier->prev->prev->prev
			);
}