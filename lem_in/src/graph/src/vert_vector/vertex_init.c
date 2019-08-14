/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:35:46 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/13 14:54:34 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	vertex_init(t_vertex *vertex, char *name, int prev, long long weight)
{
	vertex->name = (name == NULL) ? NULL : ft_strdup(name);
	vertex->prev = prev;
	vertex->weight = weight;
	vertex->adj = vector_pair_create(0);
}

void	vertex_destroy(t_vertex *vertex)
{
	if (vertex->adj != NULL)
		vector_pair_destroy(&vertex->adj);
	if (vertex->name != NULL)
		ft_strdel(&vertex->name);
}

void		vertexes_init(t_vertex *vertexes, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		vertex_init(&vertexes[i], NULL, -1, 2147483648);
		++i;
	}
}

void		vertexes_destroy(t_vertex *vertexes, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		vertex_destroy(&vertexes[i]);
		++i;
	}
}
