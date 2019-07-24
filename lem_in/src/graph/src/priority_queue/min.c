/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:08:03 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 15:50:32 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

int		Pq_min(t_Priority_queue *q)
{
	return (q->arr->data[0]);
}

void	Pq_extract_min(t_Priority_queue *q, t_Graph *g)
{
	q->arr->data[0] = q->arr->data[q->arr->size];
	vector_pop_back(q->arr);
	if (q->arr->size != 0)
		Pq_sift_down(q, g, 0);
}
