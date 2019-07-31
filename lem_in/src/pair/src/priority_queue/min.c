/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:02:17 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 10:48:28 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

int		pq_min(t_priority_queue *q)
{
	return (vector_pair_first(q->v, 0));
}

void	pq_extract_min(t_priority_queue *q)
{
	pair_swap(
			vector_pair_at(q->v, 0),
			vector_pair_at(q->v, vector_pair_len(q->v) - 1));
	vector_pair_pop_back(q->v);
	pq_sift_dawn(q, 0);	
}
