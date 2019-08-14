/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:16:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/14 17:20:38 by jblue-da         ###   ########.fr       */
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

static void		bfs_vert_handle(t_graph *g, t_int_queue *q, t_vector *f, t_vector *p)
{
	int			curr;
	int			i;
	t_vertex	*v;
	t_vertex	*u;

	curr = int_queue_pop(q);
	v = vert_vector_at(g->nodes, curr);
	i = -1;
	while ((size_t)++i < vector_pair_len(v->adj))
	{
		u = vert_vector_at(g->nodes, vector_pair_first(v->adj, i));
		if ((f->data[curr] == 0 && p->data[curr] == 1 && vector_pair_second(v->adj, i) != -1) || u->color != 0)
			continue ;
		u->color = 1;
		u->weight = v->weight + 1;
		u->prev = curr;
		int_queue_push(q, vector_pair_first(v->adj, i));
		if (vector_pair_second(v->adj, i) == -1)
			f->data[vector_pair_first(v->adj, i)] = 1;
	}
	v->color = 2;
}

void			bfs(t_graph *g, t_vector *p)
{
	t_int_queue	*q;
	t_vector	*f;

	q = int_queue_create();
	f = vector_create(vert_vector_size(g->nodes));
	bfs_init(g);
	int_queue_push(q, g->start_idx);
	while (!int_queue_isempty(q))
		bfs_vert_handle(g, q, f, p);
	int_queue_destroy(&q);
	vector_destroy(&f);
}
