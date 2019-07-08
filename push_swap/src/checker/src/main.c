/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:37:57 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 11:33:50 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int			main(int argc, char **argv)
{
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
	else if (ft_strcmp(argv[1], "-c") == 0)
		mode_color(stack_a, stack_b);
	else
		mode_default(stack_a, stack_b);
	stack_destroy(&stack_a);
	stack_destroy(&stack_b);
	return (0);
}
