/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:44:07 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:47:15 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void		mode_default(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = NULL;
	while (get_next_line(0, &operation) != 0)
	{
		if (operation_is_not_exist(operation))
			checker_error_exit(a, b, operation);
		operations_handler(a, b, operation);
		ft_strdel(&operation);
	}
	if (stack_is_sort(a) && stack_is_empty(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_strdel(&operation);
}
