/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:06:38 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:59:45 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

t_int_queue		*int_queue_create(void)
{
	t_int_queue	*q;

	q = (t_int_queue *)malloc(sizeof(t_int_queue));
	q->bar = qnode_create(0);
	q->size = 0;
	return (q);
}

void			int_queue_destroy(t_int_queue **q)
{
	size_t		i;
	t_qnode		*del_node;
	t_qnode		*iter;

	i = 0;
	iter = (*q)->bar;
	while (i <= (*q)->size)
	{
		del_node = iter;
		iter = iter->next;
		qnode_destroy(&del_node);
		++i;
	}
	qnode_destroy(&del_node);
	free(*q);
	*q = NULL;
}
