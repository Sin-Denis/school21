/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admonds_carp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:01:55 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/14 17:21:06 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void		admonds_carp(t_graph *g, int num_path)
{
	t_vector	*p;

	p = vector_create(vert_vector_size(g->nodes));
	while (num_path > 0)
	{
		bfs(g, p);
		if (vert_vector_at(g->nodes, g->end_idx)->weight == 2147483648)
			break ;
		change_weight(g, p);
		--num_path;
	}
	vector_destroy(&p);
}
