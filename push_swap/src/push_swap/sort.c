#include "push_swap.h"

void	shift_all_without_three(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		stack_shift(b, a);
}

void	sort_three_elems(t_stack *a, t_stack *b)
{
	
}

void    sort(t_stack *a, t_stack *b)
{
    shift_all_without_three(a, b);
    sort_three_elems(a, b);
    while (!stack_is_empty(b))
    {
        operations_calculate(a, b);
		choose_elem(a, b);
    }
}
