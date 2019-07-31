/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:20:04 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 15:47:46 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		change_weight(t_graph *g)
{
	t_vertex	*v;
	size_t		i;
	size_t		j;
	long long	new_dist;

	i = 0;
	while (i < vert_vector_size(g->nodes))
	{
		j = 0;
		v = vert_vector_at(g->nodes, i);
		while (j < vector_pair_len(v->adj))
		{
			new_dist = vector_pair_second(v->adj, j) + v->dist -
			vert_vector_at(g->nodes, vector_pair_first(v->adj, j))->dist;
			graph_set_weight(g, i, vector_pair_first(v->adj, j), new_dist);
			++j;
		}
		++i;
	}
}

static void		revrse_road(t_graph *g)
{
	int			idx;
	t_vertex	*v;

	idx = g->end_idx;
	v = vert_vector_at(g->nodes, idx);
	while (v->prev != g->start_idx)
	{
		graph_del_edge(g, v->prev, idx);
		idx = v->prev;
		v = vert_vector_at(g->nodes, v->prev);
	}
	graph_del_edge(g, v->prev, idx);
}

void		suurballe(t_graph *g, int num_path)
{
	while (num_path > 0)
	{
		dijkstra(g);
		change_weight(g);
		revrse_road(g);
		--num_path;
	}
}