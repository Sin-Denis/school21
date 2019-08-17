/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_roads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:45:20 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:36:22 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/output.h"

static int		partition(t_vector **roads, int l, int r)
{
	int			p;
	int			i;
	int			j;
	t_vector	*tmp;

	p = roads[(l + r) / 2]->size;
	i = l;
	j = r;
	while (i <= j)
	{
		while (roads[i]->size < p)
			++i;
		while (roads[j]->size > p)
			--j;
		if (i >= j)
			break ;
		tmp = roads[i];
		roads[i] = roads[j];
		roads[j] = tmp;
		++i;
		--j;
	}
	return (j);
}

static void		quick_sort(t_vector **roads, int l, int r)
{
	int			q;

	if (l < r)
	{
		q = partition(roads, l, r);
		quick_sort(roads, l, q);
		quick_sort(roads, q + 1, r);
	}
}

static void		put_roads(t_graph *g, t_vector **roads, int idx, int vertex_idx)
{
	t_vertex	*v;
	size_t		i;

	i = 0;
	v = vert_vector_at(g->nodes, vertex_idx);
	while (i < vector_pair_len(v->adj))
	{
		if (vector_pair_second(v->adj, i) == -1)
		{
			put_roads(g, roads, idx, vector_pair_first(v->adj, i));
			if (vertex_idx == g->end_idx)
			{
				vector_push_back(roads[idx], vertex_idx);
				++idx;
			}
		}
		++i;
	}
	if (vertex_idx != g->end_idx && vertex_idx != g->start_idx &&
	v->type != OUT)
		vector_push_back(roads[idx], vertex_idx);
}

int				get_num_roads(t_graph *g)
{
	int			res;
	size_t		i;
	t_vertex	*v;

	res = 0;
	i = 0;
	v = graph_get_vert(g, g->end_idx);
	while (i < vector_pair_len(v->adj))
	{
		if (vector_pair_second(v->adj, i) == -1)
			++res;
		++i;
	}
	return (res);
}

t_vector		**get_all_roads(t_graph *g, int num_roads)
{
	int			i;
	t_vector	**roads;

	roads = (t_vector **)malloc(sizeof(t_vector *) * (num_roads + 1));
	roads[num_roads] = NULL;
	i = -1;
	while (++i < num_roads)
		roads[i] = vector_create(0);
	put_roads(g, roads, 0, g->end_idx);
	quick_sort(roads, 0, num_roads - 1);
	return (roads);
}
