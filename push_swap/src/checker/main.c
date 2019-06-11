#include "checker.h"

int			main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = stack_create();
	stack_b = stack_create();
	if (argc < 2)
		return (0);
	if (arguments_parse(stack_a, argc, argv) == -1)
		write(2, "Error\n", 6);
	if (strstr(argv[1], "-v"))
		mode_debag(stack_a, stack_b);
	else if (strstr(argv[1], "-c"))
		mode_color(stack_a, stack_b);
	else
		mode_default(stack_a, stack_b);
	return (0);
}
