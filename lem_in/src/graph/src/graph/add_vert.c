/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:15:47 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 12:33:49 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

t_vertex	*graph_add_vert(t_graph *g, char *name, int x, int y)
{
	t_vertex	*v;

	vert_vector_push_back(g->nodes, name, x, y);
	v = vert_vector_at(g->nodes, vert_vector_size(g->nodes) - 1);
	return (v);
}

void	graph_add_start_vert(t_graph *g, char *name, int x, int y)
{
	g->start_idx = vert_vector_size(g->nodes);
	vert_vector_push_back(g->nodes, name, x, y);
}

void	graph_add_end_vert(t_graph *g, char *name, int x, int y)
{
	g->end_idx = vert_vector_size(g->nodes);
	vert_vector_push_back(g->nodes, name, x, y);
}
