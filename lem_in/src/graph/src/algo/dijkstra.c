/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:09:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 16:20:44 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		graph_init(t_Graph *g)
{
	int			i;
	t_Vertex	*v;

	i = -1;
	while (++i < g->table->capacity)
	{
		v = Vert_vector_at(g->table->data, i);
		if (v->status == EXIST)
		{
			if (i == Hash_table_idx(g->table, g->start_id))
				v->dist = 0;
			else
				v->dist = -1;
			v->prev = -1;
		}
	}
}

void	dijkstra(t_Graph *g)
{
	t_Priority_queue *q;

	Pq_create(&q);
	Pq_build(q, g);
	Pq_destroy(&q);
}
