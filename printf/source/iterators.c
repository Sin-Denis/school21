/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:58:40 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:19 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_iterator		first(t_queue *q)
{
	t_iterator	res;

	res.node = q->head;
	return (res);
}

t_iterator		last(t_queue *q)
{
	t_iterator	res;

	res.node = q->tail;
	return (res);
}

t_iterator		prev(t_iterator *i)
{
	i->node = i->node->prev;
	return (*i);
}

t_iterator		next(t_iterator *i)
{
	i->node = i->node->next;
	return (*i);
}
