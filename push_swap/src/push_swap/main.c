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
    sort(stack_a, stack_b);
    return (0);
}
