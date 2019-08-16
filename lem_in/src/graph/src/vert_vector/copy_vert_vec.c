/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_vert_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:21:13 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/16 22:40:45 by jblue-da         ###   ########.fr       */
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
	v1->idx = v2->idx;
	v1->pair_idx = v2->pair_idx;
	v1->type = v2->type;
	v1->color = v2->color;
	v1->x = v2->x;
	v1->y = v2->y;
	while (i < v2->adj->size)
	{
		vector_pair_push_back(v1->adj, v2->adj->data[i].first, v2->adj->data[i].second);
		++i;
	}
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
	vertexes_init(new_vector->data, v->capacity);
	copy(new_vector->data, v->data, v->size);
	return (new_vector);
}
