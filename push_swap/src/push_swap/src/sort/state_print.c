#include "../../inc/push_swap.h"

static void state_item_print(t_stack *s)
{
	int		i;
	t_node	*iter;

	i = -1;
	iter = s->barrier->prev;
	while (++i < s->size)
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

void	state_print(t_stack *a, t_stack *b)
{
	state_item_print(a);
	state_item_print(b);
}