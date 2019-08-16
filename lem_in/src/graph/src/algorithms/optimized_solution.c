/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:57:19 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/16 14:58:22 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void		optimized_solution(t_graph *g, int num_path)
{
	while (num_path > 0)
	{
		bfs(g);
		if (vert_vector_at(g->nodes, g->end_idx)->weight == 2147483648)
			break ;
		change_path(g);
		--num_path;
	}
}