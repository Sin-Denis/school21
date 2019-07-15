/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:56 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 10:01:06 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

int				stack_reverse_rotate(t_stack *s)
{
	t_node		*node;

	if (s->size <= 1)
		return (0);
	node = s->barrier->next;
	node->next->prev = s->barrier;
	s->barrier->next = node->next;
	s->barrier->prev->next = node;
	node->prev = s->barrier->prev;
	node->next = s->barrier;
	s->barrier->prev = node;
	return (0);
}
