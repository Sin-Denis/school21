/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:15:47 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 15:54:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	graph_add_vert(t_graph *g, char *name)
{
	vert_vector_push_back(g->nodes, name);
}

void	graph_add_start_vert(t_graph *g, char *name)
{
	g->start_idx = vert_vector_size(g->nodes);
	vert_vector_push_back(g->nodes, name);
}

void	graph_add_end_vert(t_graph *g, char *name)
{
	g->end_idx = vert_vector_size(g->nodes);
	vert_vector_push_back(g->nodes, name);
}
