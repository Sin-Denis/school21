/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:03:26 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:34 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			queue_del(t_queue *q, t_iterator *i)
{
	if (q->head == i->node)
		q->head = q->head->next;
	else if (q->tail == i->node)
		q->tail = q->tail->prev;
	if (i->node->next != NULL)
		i->node->next->prev = i->node->prev;
	if (i->node->prev != NULL)
		i->node->prev->next = i->node->next;
	ft_strdel(&i->node->data);
	free(i->node);
	i->node = NULL;
	q->size--;
}

char			*queue_pop(t_queue *q)
{
	char		*res;
	t_iterator	i;

	i = last(q);
	res = ft_strdup(fetch(&i));
	queue_del(q, &i);
	return (res);
}
