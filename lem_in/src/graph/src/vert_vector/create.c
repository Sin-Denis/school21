/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:06:28 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/17 11:44:45 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void static	init(t_Vertex *data, size_t size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		data[i].status = BLANK;
		data[i].id = NULL;
		data[i].adj = NULL;
	}
}

void		Vert_vector_create(t_Vert_vector **v)
{
	(*v) = (t_Vert_vector *)malloc(sizeof(t_Vert_vector));
	(*v)->data = (t_Vertex *)malloc(sizeof(t_Vertex) * 8);
	(*v)->size = 0;
	(*v)->capacity = 8;
}

void		Vert_vector_create_size(t_Vert_vector **v, size_t size)
{
	(*v) = (t_Vert_vector *)malloc(sizeof(t_Vert_vector));
	(*v)->data = (t_Vertex *)malloc(sizeof(t_Vertex) * size * 2);
	(*v)->size = size;
	(*v)->capacity = size * 2;
	init((*v)->data, size);
}
