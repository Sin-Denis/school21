/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sift.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:28:05 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 15:55:06 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void	swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static char	compare(t_Graph *g, int v, int u)
{
	t_Vertex *v1;
	t_Vertex *v2;

	v1 = Graph_get_vert(g, v);
	v2 = Graph_get_vert(g, u);
	if (v1->dist < v2->dist)
		return (-1);
	if (v1->dist > v2->dist)
		return (1);
	return (0);
}

void		Pq_sift_down(t_Priority_queue *q, t_Graph *g, int idx)
{
    int		left;
	int		right;
	int		less;
	
	left = idx * 2 + 1;
	right = left + 1;
	less = idx;
	if (compare(g, left, less) == -1)
		less = left;
	if (compare(g, right, less) == 1)
		less = right;
	if (less != idx)
	{
		swap(&q->arr->data[less], &q->arr->data[idx]);
		Pq_sift_down(q, g, less);
	}
}

void	Pq_sift_up(t_Priority_queue *q, t_Graph *g, int idx)
{
	int parent;

    while (idx > 0)
	{
		parent = (idx - 1) / 2;
		if (compare(g, parent, idx) == -1 ||
			compare(g, parent, idx) == 0)
			return ;
		swap(&q->arr->data[parent], &q->arr->data[idx]);
		idx = parent;
	}
}
