/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrease.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:08:54 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 16:51:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

void		pq_decrease(t_priority_queue *q, int first, int second)
{
	t_pair	*p;
	size_t	i;

	i = 0;
	while (i < vector_pair_len(q->v))
	{
		p = vector_pair_at(q->v, i);
		if (p->first == first)
			break;
		++i;
	}
	p->second = second;
	pq_sift_up(q, i);
}
