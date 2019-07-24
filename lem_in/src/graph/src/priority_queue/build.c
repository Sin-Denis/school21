/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:07:47 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 16:23:02 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Pq_build(t_Priority_queue *q, t_Graph *g)
{
	int			i;
	t_Vertex	*v;

	i = -1;
	while (++i < g->table->capacity)
	{
		v = Vert_vector_at(g->table->data, i);
		if (v->status == EXIST)
			Pq_insert(q, g, i);
	}
}
