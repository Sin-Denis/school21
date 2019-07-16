/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:28:13 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 14:31:58 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		arr_copy(t_Vertex *dst, t_Vertex *src, int size)
{
	int			i;

	i = -1;
	while (++i < size)
		dst[i] = src[i];
}

static void		grow(t_Vert_vector *v)
{
    t_Vertex	*new_data;

	new_data = (t_Vertex *)malloc(sizeof(t_Vertex) * v->capacity * 2);
	arr_copy(new_data, v->data, v->capacity);
	free(v->data);
	v->data = new_data;
	v->capacity *= 2;
}

void			Vert_vector_push_back(t_Vert_vector *v, char *name)
{
    if (v->size == v->capacity)
		grow(v);
	v->data[v->size].id = ft_strdup(name);
	v->data[v->size].status = EXIST;
}

