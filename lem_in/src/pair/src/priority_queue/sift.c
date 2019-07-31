/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sift.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:53:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 10:48:17 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

void		pq_sift_dawn(t_priority_queue *q, int idx)
{
	int		left;
	int		right;
	int		less;

	while ((size_t)(2 * idx + 1) < vector_pair_len(q->v))
	{
		left = idx * 2 + 1;
		right = left + 1;
		less = left;
		if ((size_t)right < vector_pair_len(q->v) && vector_pair_second(q->v, right) < vector_pair_second(q->v, less))
			less = right;
		if (vector_pair_second(q->v, idx) < vector_pair_second(q->v, less))
			break ;
		pair_swap(vector_pair_at(q->v, less), vector_pair_at(q->v, idx));
		idx = less;
	}
}

void		pq_sift_up(t_priority_queue *q, int idx)
{
	int		parent;

	while (idx > 0)
	{
		parent = (idx - 1) / 2;
		if (vector_pair_second(q->v, parent) <= vector_pair_second(q->v, idx))
			return ;
		pair_swap(vector_pair_at(q->v, idx), vector_pair_at(q->v, parent));
		idx = parent;
	}
}
