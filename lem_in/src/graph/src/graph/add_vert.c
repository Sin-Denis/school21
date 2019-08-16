/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:15:47 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 20:15:02 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	graph_add_vert(t_graph *g, char *name, int x, int y)
{
	vert_vector_push_back(g->nodes, name, x, y);
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
