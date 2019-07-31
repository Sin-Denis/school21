/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:16:53 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 13:33:30 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void			graph_add_edge(t_graph *g, int id1, int id2)
{
	t_vertex	*v1;

	v1 = vert_vector_at(g->nodes, id1);
	if (v1->adj == NULL)
		v1->adj = vector_pair_create(0);
	vector_pair_push_back(v1->adj, id2, 1);
}

void			graph_del_edge(t_graph *g, int id1, int id2)
{
	t_vertex	*v1;

	v1 = vert_vector_at(g->nodes, id1);
	vector_pair_del(v1->adj, id2);
}
