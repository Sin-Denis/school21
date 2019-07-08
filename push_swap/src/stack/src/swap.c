/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:11 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:39:12 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

int				stack_swap(t_stack *s)
{
	t_node		*top;
	t_node		*prev_top;

	if (s->size <= 1)
		return (-1);
	top = s->barrier->prev;
	prev_top = top->prev;
	prev_top->next = top->next;
	prev_top->prev->next = top;
	top->prev = prev_top->prev;
	top->next = prev_top;
	prev_top->prev = top;
	s->barrier->prev = prev_top;
	return (0);
}
