/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:42:04 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 14:55:09 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		bfs_init(t_graph *g)
{
	size_t		i;

	i = 0;
	while (i < vert_vector_size(g->nodes))
	{
		vert_vector_at(g->nodes, i)->color = 0;
		vert_vector_at(g->nodes, i)->prev = -1;
		vert_vector_at(g->nodes, i)->weight = 2147483648;
		++i;
	}
	vert_vector_at(g->nodes, g->start_idx)->color = 1;
	vert_vector_at(g->nodes, g->start_idx)->weight = 0;
}

static void		bfs_handler(t_graph *g, t_int_queue *q, t_vertex *v)
{
	size_t		i;
	t_vertex	*u;

	i = 0;
	while (i < vector_pair_len(v->adj))
	{
		u = graph_get_vert(g, vector_pair_first(v->adj, i));
		if (u->color == 0)
		{
			u->color = 1;
			u->weight = v->weight + 1;
			u->prev = v->idx;
			int_queue_push(q, u->idx);
		}
		++i;
	}
}

void			bfs(t_graph *g)
{
	t_int_queue	*q;
	t_vertex	*v;

	q = int_queue_create();
	bfs_init(g);
	int_queue_push(q, g->start_idx);
	while (!int_queue_isempty(q))
	{
		v = graph_get_vert(g, int_queue_pop(q));
		bfs_handler(g, q, v);
		v->color = 2;
	}
	int_queue_destroy(&q);
}

void			change_path(t_graph *g)
{
	t_vertex	*v;
	t_vertex	*u;

	v = graph_get_vert(g, g->end_idx);
	while (v->idx != g->start_idx)
	{
		u = graph_get_vert(g, v->prev);
		if (vertex_get_weight(u, v->idx) == -1)
			graph_del_dir_edge(g, u->idx, v->idx);
		else
		{
			graph_del_dir_edge(g, u->idx, v->idx);
			graph_add_dir_edge(g, v->idx, u->idx);
			graph_set_weight(g, v->idx, u->idx, -1);
		}
		v = u;
	}
}
