/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:20:04 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/07 11:04:45 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

// static void		clean_path(t_graph *g)
// {
// 	int			idx;
// 	t_vertex	*v;

// 	idx = g->end_idx;
// 	v = vert_vector_at(g->nodes, vert_vector_at(g->nodes, idx)->prev);
// 	idx = vert_vector_at(g->nodes, idx)->prev;
// 	while (v->prev != -1 && v->prev != g->start_idx)
// 	{
// 		vector_pair_destroy(&v->adj);
// 		v->adj = vector_pair_create(0);
// 		graph_add_dir_edge(g, idx, v->prev);
// 		graph_set_weight(g, idx, v->prev, 0);
// 		idx = v->prev;
// 		v = vert_vector_at(g->nodes, v->prev);
// 	}
// 	if (v->prev != -1)
// 	{
// 		vector_pair_destroy(&v->adj);
// 		v->adj = vector_pair_create(0);
// 		graph_add_dir_edge(g, idx, v->prev);
// 		graph_set_weight(g, idx, v->prev, 0);
// 	}
// }

static void		change_weight(t_graph *g)
{
	t_vertex	*v;
	size_t		i;
	size_t		j;
	long long	new_weight;

	i = 0;
	while (i < vert_vector_size(g->nodes))
	{
		j = 0;
		v = vert_vector_at(g->nodes, i);
		while (v->adj != NULL && j < vector_pair_len(v->adj))
		{
			// if (vector_pair_first(v->adj, j) == 0)
			// {
			// 	++j;
			// 	continue ;
			// }
			new_weight = vector_pair_second(v->adj, j) + v->weight -
			vert_vector_at(g->nodes, vector_pair_first(v->adj, j))->weight;
			graph_set_weight(g, i, vector_pair_first(v->adj, j), new_weight);
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
	while (v->prev != -1 && v->prev != g->start_idx)
	{
		graph_del_dir_edge(g, v->prev, idx);
		graph_set_weight(g, idx, v->prev, 0);
		idx = v->prev;
		v = vert_vector_at(g->nodes, v->prev);
	}
	if (v->prev != -1)
	{
		graph_del_dir_edge(g, v->prev, idx);
		graph_set_weight(g, idx, v->prev, 0);
	}
}

void		suurballe(t_graph *g)
{
		dijkstra(g);
		change_weight(g);
		revrse_road(g);
		dijkstra(g);
		revrse_road(g);
}