/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:03 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:39:03 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

int	stack_simultaneous_reverse_rotate(t_stack *a, t_stack *b)
{
	if (stack_reverse_rotate(a) == -1 || stack_reverse_rotate(b) == -1)
		return (-1);
	return (0);
}
