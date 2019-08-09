/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:35:46 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/08 16:45:37 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	vertex_init(t_vertex *vertex, char *name, int prev, long long weight)
{
	vertex->name = name == NULL ? NULL : ft_strdup(name);
	vertex->prev = prev;
	vertex->weight = weight;
	vertex->adj = vector_pair_create(0);
}

void	vertex_destroy(t_vertex *vertex)
{
	vector_pair_destroy(&vertex->adj);
	ft_strdel(&vertex->name);
}

void		vertexes_init(t_vertex *vertexes, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		vertex_init(&vertexes[i], NULL, -1, 2147483648L);
		++i;
	}
}

void		vertexes_destroy(t_vertex **vertexes, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		vertex_destroy(&(*vertexes)[i]);
		++i;
	}
}
