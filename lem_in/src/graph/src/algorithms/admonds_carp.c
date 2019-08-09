/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admonds_carp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:01:55 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 12:33:46 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void	bfs_init(t_graph *g)
{
	size_t	i;

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
	int curr;
	int i;
	t_vertex *v;
	t_vertex *u;

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

static void		bfs(t_graph *g, t_vector *p)
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

static void	change_weight(t_graph *g, t_vector *p)
{
	int			idx;
	t_vertex	*v;

	idx = g->end_idx;
	v = vert_vector_at(g->nodes, idx);
	while (v->prev != -1 && v->prev != g->start_idx)
	{
		p->data[v->prev] = 1;
		if (vert_vector_at(g->nodes, v->prev)->adj->data[idx].second == -1)
			graph_set_weight(g, idx, v->prev, 1);
		else
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

// static void	get_roads_len(t_vector *lens, t_graph *g)
// {
	
// }

// static void		get_attitude_roads(t_vector *lens, t_vector *attitude_roads, int num_roads)
// {
// 	int		i;
// 	int		len_big_road;

// 	i = num_roads - 1;
// 	len_big_road = vector_get_elem(lens, 0);
// 	vector_set_elem(attitude_roads, i, 1);
// 	while (--i >= 0)
// 		vector_set_elem(attitude_roads, i, len_big_road - vector_get_elem(lens, i) + 1);
// }

// static int		get_num_lens(t_vector *attitude_roads, t_vector *lens, int num_ants)
// {
// 	int			i;
// 	int			first_road_distribution;
// 	int			num_lines;
// 	int			add_val;
// 	int			rem_val;

// 	i = -1;
// 	first_road_distribution = num_ants > vector_get_elem(attitude_roads, 0) ? vector_get_elem(attitude_roads, 0) : num_ants;
// 	add_val = num_ants / attitude_roads->size;
// 	rem_val = num_ants % attitude_roads->size;
// 	while (num_ants > 0 && ++i < distribution->size)
// 	{
// 		distribution->data[i] += add_val;
// 		if (i < rem_val)
// 			++distribution->data[i];
// 	}
// }

// int analysis(t_graph *g, t_vector *attitude_roads)
// {
// 	int			min_num_path;
// 	id_t		num_lens;
// 	int			num_path;
// 	t_vector	*p;
// 	t_vector	*roads_len;

// 	p = vector_create(vert_vector_size(g->nodes));
// 	roads_len = vector_create(0);
// 	num_path = 0;
// 	while (1)
// 	{
// 		++num_path;
// 		bfs(g, p);
// 		if (vert_vector_at(g->nodes, g->end_idx)->weight == 2147483648)
// 			break ;
// 		change_weight(g, p);
// 		get_roads_len(roads_len, g);
// 		get_attitude_roads(roads_len, attitude_roads, num_path);
		
// 	}
// 	vector_destroy(&p);
// 	vector_destroy(&roads_len);
// }


void		admonds_carp(t_graph *g, int num_path)
{
	t_vector	*p;

	p = vector_create(vert_vector_size(g->nodes));
	while (num_path > 0)
	{
		bfs(g, p);
		if (vert_vector_at(g->nodes, g->end_idx)->weight == 2147483648)
			break ;
		change_weight(g, p);
		--num_path;
	}
	vector_destroy(&p);
}
