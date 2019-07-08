/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:37:02 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:01:23 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	stack_destroy(&a);
	stack_destroy(&b);
	write(2, "Error\n", 6);
	exit(1);
}
