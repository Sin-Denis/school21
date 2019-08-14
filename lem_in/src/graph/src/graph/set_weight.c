/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:16:47 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 15:32:16 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	graph_set_weight(t_graph *g, int id1, int id2, long long weight)
{
	size_t		i;
	t_vertex	*v;

	v = vert_vector_at(g->nodes, id1);
	i = 0;
	while (i < vector_pair_len(v->adj))
	{
		if (vector_pair_first(v->adj, i) == id2)
			break ;
		++i;
	}
	vector_pair_store(v->adj, i, id2, weight);
}
