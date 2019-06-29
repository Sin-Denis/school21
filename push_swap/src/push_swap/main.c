#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack     *stack_a;
    t_stack     *stack_b;

    stack_a = stack_create();
    stack_b = stack_create();
    if (argc < 2)
	    return (0);
    if (arguments_parse(stack_a, argc, argv) == -1)
        error_exit(stack_a, stack_b);
    order_calculate(stack_a);
    int			i;
	t_node		*iter;

	i = -1;
	iter = stack_a->barrier->prev;
	while (++i < stack_a->size)
	{
		ft_printf("val: %d|||ord_idx: %d\n", iter->value, iter->order_idx);
		iter = iter->prev;
	}
    sort(stack_a, stack_b);
    return (0);
}
