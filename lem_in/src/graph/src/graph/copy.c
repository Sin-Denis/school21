/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:12:33 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 16:33:41 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

t_graph		*graph_copy(t_graph *g)
{
	t_graph	*new_graph;

	new_graph = (t_graph *)malloc(sizeof(t_graph));
	new_graph->num_ants = g->num_ants;
	new_graph->start_idx = g->start_idx;
	new_graph->end_idx = g->end_idx;
	new_graph->nodes = vert_vector_copy(g->nodes);
	return (new_graph);
}
