/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:54 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

void			stack_push_front(t_stack *s, int elem)
{
	t_node		*new_node;

	new_node = node_create(elem);
	new_node->prev = s->barrier;
	if (s->size == 0)
	{
		s->barrier->prev = new_node;
		s->barrier->next = new_node;
		new_node->next = s->barrier;
	}
	else
	{
		s->barrier->next->prev = new_node;
		new_node->next = s->barrier->next;
		s->barrier->next = new_node;
	}
	s->size++;
}
