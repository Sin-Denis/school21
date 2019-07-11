/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:58 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/11 13:34:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

int				stack_rotate(t_stack *s)
{
	t_node		*node;

	if (s->size < 1)
		return (-1);
	if (s->size == 1)
		return (0);
	node = s->barrier->prev;
	node->prev->next = s->barrier;
	s->barrier->prev = node->prev;
	s->barrier->next->prev = node;
	node->next = s->barrier->next;
	node->prev = s->barrier;
	s->barrier->next = node;
	return (0);
}
