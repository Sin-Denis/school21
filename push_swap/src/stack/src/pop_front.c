/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:45 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:46 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

void			stack_pop_front(t_stack *s)
{
	t_node		*delete_node;

	delete_node = s->barrier->next;
	s->barrier->next = delete_node->next;
	delete_node->next->prev = s->barrier;
	node_destroy(&delete_node);
	s->size--;
}
