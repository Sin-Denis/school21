/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:27:09 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/02 14:18:46 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

void		int_queue_push(t_int_queue *q, int key)
{
	t_qnode	*new_node;

	new_node = qnode_create(key);
	if (q->size == 0)
	{
		q->bar->next = new_node;
		q->bar->prev = new_node;
		new_node->prev = q->bar;
		new_node->next = q->bar;
	}
	else
	{
		new_node->next = q->bar->next;
		new_node->prev = q->bar;
		q->bar->next->prev = new_node;
		q->bar->next = new_node;
	}
	++q->size;
}

int			int_queue_pop(t_int_queue *q)
{
	t_qnode	*del_node;
	int		res;

	del_node = q->bar->prev;
	res = del_node->key;
	del_node->prev->next = q->bar;
	q->bar->prev = del_node->prev;
	qnode_destroy(&del_node);
	--q->size;
	return (res);
}

char		int_queue_isempty(t_int_queue *q)
{
	return (q->size == 0);
}
