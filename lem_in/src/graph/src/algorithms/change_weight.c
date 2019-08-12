/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_weight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:19:16 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/12 12:18:43 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void			change_weight(t_graph *g, t_vector *p)
{
	int			idx;
	t_vertex	*v;
	t_vertex	*u;

	idx = g->end_idx;
	v = vert_vector_at(g->nodes, idx);
	while (v->prev != -1 && v->prev != g->start_idx)
	{
		p->data[v->prev] = 1;
		u = vert_vector_at(g->nodes, v->prev);
		if (vertex_get_weight(u, idx) != -1)
			graph_set_weight(g, idx, v->prev, -1);
		graph_del_dir_edge(g, v->prev, idx);
		idx = v->prev;
		v = vert_vector_at(g->nodes, v->prev);
	}
	if (v->prev != -1)
	{
		graph_del_dir_edge(g, v->prev, idx);
		graph_set_weight(g, idx, v->prev, -1);
	}
}
