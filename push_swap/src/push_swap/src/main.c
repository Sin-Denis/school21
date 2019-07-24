/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:36:54 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/22 18:12:44 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = stack_create();
	stack_b = stack_create();
	if (argc < 2)
	{
		stack_destroy(&stack_a);
		stack_destroy(&stack_b);
		return (0);
	}
	if (arguments_parse(stack_a, argc, argv) == -1)
		error_exit(stack_a, stack_b);
	order_calculate(stack_a);
	sort(stack_a, stack_b);
	return (0);
}
