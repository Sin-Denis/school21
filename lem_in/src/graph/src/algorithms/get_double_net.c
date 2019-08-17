/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_net.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:35:31 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:19:32 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		add_out_init(t_graph *g)
{
	t_vertex	*v;
	size_t		i;

	i = 0;
	while (i < vert_vector_size(g->nodes))
	{
		v = graph_get_vert(g, i);
		if ((int)i == g->start_idx || (int)i == g->end_idx)
			v->color = 1;
		else
			v->color = 0;
		++i;
	}
}

static void		add_out_start_handler(t_graph *g, t_int_queue *q, int v_idx)
{
	size_t		i;
	t_vertex	*u;
	t_vertex	*v;

	i = 0;
	v = graph_get_vert(g, v_idx);
	while (i < vector_pair_len(v->adj))
	{
		u = graph_get_vert(g, vector_pair_first(v->adj, i));
		u->color = 1;
		graph_del_dir_edge(g, u->idx, v->idx);
		int_queue_push(q, u->idx);
		++i;
	}
}

static void		add_out_handler_item(t_graph *g,
					t_int_queue *q, t_vertex *v, t_vertex *u)
{
	size_t		i;
	t_vertex	*w;

	i = 0;
	while (i < vector_pair_len(v->adj))
	{
		w = graph_get_vert(g, vector_pair_first(v->adj, i));
		if (w->idx == g->end_idx)
			graph_del_edge(g, v->idx, w->idx);
		else
			graph_del_dir_edge(g, v->idx, w->idx);
		graph_add_dir_edge(g, u->idx, w->idx);
		if (w->color == 0 && w->type != OUT)
		{
			w->color = 1;
			int_queue_push(q, w->idx);
		}
	}
	graph_add_dir_edge(g, v->idx, u->idx);
}

static void		add_out_handler(t_graph *g, t_int_queue *q, int v_idx)
{
	t_vertex	*u;
	t_vertex	*v;
	char		*str;

	str = ft_strjoin("@", g->nodes->data[v_idx].name);
	u = graph_add_vert(g, str, -1, -1);
	free(str);
	v = graph_get_vert(g, v_idx);
	v->type = IN;
	u->type = OUT;
	v->pair_idx = u->idx;
	u->pair_idx = v->idx;
	u->color = 2;
	add_out_handler_item(g, q, v, u);
}

t_graph			*get_double_net(t_graph *g)
{
	t_graph		*double_network;
	t_int_queue	*q;
	t_vertex	*v;
	int			v_idx;

	double_network = graph_copy(g);
	q = int_queue_create();
	add_out_init(double_network);
	int_queue_push(q, double_network->start_idx);
	while (!int_queue_isempty(q))
	{
		v_idx = int_queue_pop(q);
		if (double_network->start_idx == v_idx)
			add_out_start_handler(double_network, q, v_idx);
		else
			add_out_handler(double_network, q, v_idx);
		v = graph_get_vert(double_network, v_idx);
		v->color = 2;
	}
	int_queue_destroy(&q);
	return (double_network);
}
