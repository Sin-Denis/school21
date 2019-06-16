#include "checker.h"

int			main(int argc, char **argv) {
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	stack_a = stack_create();
	stack_b = stack_create();
	if (arguments_parse(stack_a, argc, argv) == -1)
	{
		stack_destroy(&stack_a);
		stack_destroy(&stack_b);
		write(1, "Error\n", 6);
		exit(1);
	}
	if (ft_strcmp(argv[1], "-v") == 0)
		mode_debug(stack_a, stack_b);
	else if (ft_strcmp(argv[1], "-c"))
		ft_printf("Handler this flag\n");
	else
		ft_printf("Mode default\n");
	stack_destroy(&stack_a);
	stack_destroy(&stack_b);
	return (0);
}
