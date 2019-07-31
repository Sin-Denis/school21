/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:16:53 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 09:35:52 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	graph_add_edge(t_graph *g, int id1, int id2)
{
	t_vertex *v1;
	t_vertex *v2;

	v1 = vert_vector_at(g->nodes, id1);
	v2 = vert_vector_at(g->nodes, id2);
	if (v1->adj == NULL)
		v1->adj = vector_pair_create(0);
	if (v2->adj == NULL)
		v2->adj = vector_pair_create(0);
	if (id2 != g->start_idx && id1 != g->end_idx)
		vector_pair_push_back(v1->adj, id2, 1);
	if (id1 != g->start_idx && id2 != g->end_idx)
		vector_pair_push_back(v2->adj, id1, 1);
}
