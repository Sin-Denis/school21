/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_roads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:34:14 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/12 10:27:25 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

int		get_num_roads(t_graph *g)
{
	int			res;
	size_t		i;
	t_vertex	*v;

	res = 0;
	i = 0;
	v = vert_vector_at(g->nodes, g->end_idx);
	while (i < vector_pair_len(v->adj))
	{
		if (vector_pair_second(v->adj, i) == -1)
			++res;
		++i;
	}
	return (res);
}
