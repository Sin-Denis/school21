/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:04:28 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:36 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			queue_push_back(t_queue *q, char *value)
{
	t_iterator	res;

	res.node = (t_node *)malloc(sizeof(t_node));
	if (res.node == NULL)
		exit(1);
	res.node->next = NULL;
	res.node->prev = NULL;
	store(&res, value);
	if (q->size == 0)
	{
		q->head = res.node;
		q->tail = res.node;
	}
	else
	{
		q->tail->next = res.node;
		res.node->prev = q->tail;
		res.node->next = NULL;
		q->tail = res.node;
	}
	q->size++;
}

void			queue_insert(t_queue *q, t_iterator *i, char *value)
{
	t_iterator	res;

	if (q->head == i->node && i->node == NULL)
	{
		queue_push_back(q, value);
		return ;
	}
	if (i->node == NULL)
		exit(1);
	res.node = (t_node *)malloc(sizeof(t_node));
	if (res.node == NULL)
		exit(1);
	res.node->next = NULL;
	res.node->prev = NULL;
	store(&res, value);
	res.node->prev = i->node->prev;
	res.node->next = i->node;
	if (res.node->prev != NULL)
		res.node->prev->next = res.node;
	i->node->prev = res.node;
	if (i->node == q->head)
		q->head = res.node;
	q->size++;
}

void			queue_push(t_queue *q, char *value)
{
	t_iterator	begin;

	begin = first(q);
	queue_insert(q, &begin, value);
}
