/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:31:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 09:50:09 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void vertex_copy(t_vertex *v1, t_vertex *v2)
{
	size_t	i;

	i = 0;
	v1->name = ft_strdup(v2->name);
	v1->prev = v2->prev;
	v1->dist = v2->dist;
	while (v2->adj != NULL && i < v2->adj->size)
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

static void grow(t_vert_vector *v)
{
	t_vertex	*new_data;

	new_data = (t_vertex *)malloc(sizeof(t_vertex) * v->capacity * 2);
	copy(new_data, v->data, v->capacity);
	v->capacity *= 2;
	vertexes_destroy(&v->data, v->size);
	free(v->data);
	v->data = new_data;
}

void		vert_vector_push_back(t_vert_vector *v, char *name)
{
	if (v->size == v->capacity)
		grow(v);
	vertex_init(&v->data[v->size], name, -1, 2147483648);
	++v->size;
}
