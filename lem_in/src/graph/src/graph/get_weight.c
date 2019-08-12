/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:14:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/12 12:18:19 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

long long	vertex_get_weight(t_vertex *vertex1, int vertex2_idx)
{
	size_t	i;

	i = 0;
	while (i < vector_pair_len(vertex1->adj))
	{
		if (vector_pair_first(vertex1->adj, i) == vertex2_idx)
			return (vector_pair_second(vertex1->adj, i));
		++i;
	}
	return (-1);
}
