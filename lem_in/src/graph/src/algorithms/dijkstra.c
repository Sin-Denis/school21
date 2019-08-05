/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:40:13 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/05 13:23:16 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void				graph_init(t_graph *g)
{
	t_vertex			*v;
	size_t				i;

	i = 0;
	while (i < vert_vector_size(g->nodes))
	{
		g->nodes->data[i].weight = 2147483648;
		g->nodes->data[i].prev = -1;
		++i;
	}
	v = vert_vector_at(g->nodes, g->start_idx);
	v->weight = 0;

}

static t_priority_queue	*queue_build(t_graph *g)
{
	t_vertex			*v;
	size_t				i;
	t_priority_queue	*q;

	i = 0;
	q = pq_create();
	while (i < vert_vector_size(g->nodes))
	{
		v = vert_vector_at(g->nodes, i);
		pq_insert(q, i, v->weight);
		++i;
	}
	return (q);
}

static void				relax(t_graph *g, t_priority_queue *q, t_vector *visited, int idx)
{
	size_t				i;
	t_vertex			*u;
	t_vertex			*v;

	i = 0;
	v = vert_vector_at(g->nodes, idx);
	while (v->adj != NULL && i < vector_pair_len(v->adj))
	{
		if (vector_get_elem(visited, vector_pair_first(v->adj, i)))
		{
			++i;
			continue ;
		}
		u = vert_vector_at(g->nodes, vector_pair_first(v->adj, i));
		if ((long long)(v->weight + vector_pair_second(v->adj, i)) < u->weight)
		{
			u->weight = v->weight + vector_pair_second(v->adj, i);
			u->prev = idx;
			pq_decrease(q, vector_pair_first(v->adj, i), u->weight);
		}
		++i;
	}
}

void					dijkstra(t_graph *g)
{
	t_priority_queue	*q;
	t_vector			*visited;
	int					vertex_idx;

	visited = vector_create(vert_vector_size(g->nodes));
	
	graph_init(g);
	q = queue_build(g);
	while (!pq_isempty(q))
	{
		vertex_idx = pq_min(q);
		pq_extract_min(q);
		relax(g, q, visited, vertex_idx);
		vector_set_elem(visited, vertex_idx, 1);
	}
	vector_destroy(&visited);
	pq_destroy(&q);
}
