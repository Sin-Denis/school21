/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vert_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:20:32 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/16 21:42:02 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

t_vert_vector		*vert_vector_create(int size)
{
	t_vert_vector	*v;

	v = (t_vert_vector *)malloc(sizeof(t_vert_vector));
	if (size == 0)
	{
		v->data = (t_vertex *)malloc(sizeof(t_vertex) * 5);
		v->size = 0;
		v->capacity = 5;
	}
	else
	{
		v->data = (t_vertex *)malloc(sizeof(t_vertex) * size * 2);
		v->size = size;
		v->capacity = size * 2;
	}
	vertexes_init(v->data, v->capacity);
	return (v);
}

void				vert_vector_destroy(t_vert_vector **v)
{
	vertexes_destroy((*v)->data, (*v)->capacity);
	free((*v)->data);
	free(*v);
	*v = NULL;
}
