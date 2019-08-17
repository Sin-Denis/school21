/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:31:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:25:15 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		vertex_copy(t_vertex *v1, t_vertex *v2)
{
	size_t		i;

	i = 0;
	v1->name = ft_strdup(v2->name);
	v1->prev = v2->prev;
	v1->weight = v2->weight;
	v1->idx = v2->idx;
	v1->pair_idx = v2->pair_idx;
	v1->type = v2->type;
	v1->x = v2->x;
	v1->y = v2->y;
	v1->color = v2->color;
	while (i < v2->adj->size)
	{
		vector_pair_push_back(v1->adj, v2->adj->data[i].first,
		v2->adj->data[i].second);
		++i;
	}
}

static void		copy(t_vertex *dst, t_vertex *src, int size)
{
	int			i;

	i = -1;
	while (++i < size)
		vertex_copy(&dst[i], &src[i]);
}

static void		grow(t_vert_vector *v)
{
	t_vertex	*new_data;

	new_data = (t_vertex *)malloc(sizeof(t_vertex) * v->capacity * 2);
	vertexes_init(new_data, v->capacity * 2);
	copy(new_data, v->data, v->size);
	vertexes_destroy(v->data, v->size);
	v->capacity *= 2;
	free(v->data);
	v->data = new_data;
}

void			vert_vector_push_back(t_vert_vector *v,
char *name, int x, int y)
{
	if (v->size == v->capacity)
		grow(v);
	v->data[v->size].idx = v->size;
	v->data[v->size].name = ft_strdup(name);
	v->data[v->size].prev = -1;
	v->data[v->size].weight = 2147483648;
	v->data[v->size].x = x;
	v->data[v->size].y = y;
	++v->size;
}
