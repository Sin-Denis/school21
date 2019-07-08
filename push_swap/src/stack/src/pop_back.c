/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:42 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:43 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

void			stack_pop_back(t_stack *s)
{
	t_node		*delete_node;

	delete_node = s->barrier->prev;
	s->barrier->prev = delete_node->prev;
	delete_node->prev->next = s->barrier;
	node_destroy(&delete_node);
	s->size--;
}
