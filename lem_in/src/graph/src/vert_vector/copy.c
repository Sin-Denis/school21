/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:21:13 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 17:12:27 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void vertex_copy(t_vertex *v1, t_vertex *v2)
{
	size_t	i;

	i = 0;
	v1->name = v2->name == NULL ? NULL : ft_strdup(v2->name);
	v1->prev = v2->prev;
	v1->weight = v2->weight;
	while (i < v2->adj->size)
	{
		vector_pair_push_back(v1->adj, v2->adj->data[i].first, v2->adj->data[i].second);
		++i;
	}
	if (v2->adj->size == 0)
		v1->adj = vector_pair_create(0);
}

static void copy(t_vertex *dst, t_vertex *src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		vertex_copy(&dst[i], &src[i]);
}

t_vert_vector		*vert_vector_copy(t_vert_vector *v)
{
	t_vert_vector	*new_vector;
	size_t			i;

	i = 0;
	new_vector = (t_vert_vector *)malloc(sizeof(t_vert_vector));
	new_vector->capacity = v->capacity;
	new_vector->size = v->size;
	new_vector->data = (t_vertex *)malloc(sizeof(t_vertex) * v->capacity);
	while (i < v->capacity)
	{
		new_vector->data[i].adj = vector_pair_create(0);
		++i;
	}
	copy(new_vector->data, v->data, v->size);
	return (new_vector);
}
