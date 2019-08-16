/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:15:33 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 20:10:13 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

t_graph				*graph_create(void)
{
    t_graph *graph;

    graph = (t_graph *)malloc(sizeof(t_graph));
    graph->nodes = vert_vector_create(0);
    graph->start_idx = -1;
    graph->end_idx = -1;
	graph->num_ants = -1;
    return (graph);
}

void				graph_destroy(t_graph **g)
{
    vert_vector_destroy(&(*g)->nodes);
    free(*g);
    *g = NULL;
}
