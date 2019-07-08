/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:09 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:39:10 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

int	stack_simultaneous_swap(t_stack *a, t_stack *b)
{
	if (stack_swap(a) == -1 || stack_swap(b) == -1)
		return (-1);
	return (0);
}
