/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 08:32:04 by sindenis          #+#    #+#             */
/*   Updated: 2019/07/17 08:35:41 by sindenis         ###   ########.fr       */
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

void	Vert_vector_resize(t_Vert_vector *v, size_t new_size)
{
	t_Vertex	*new_data;

	new_data = (t_Vertex *)malloc(sizeof(t_Vertex) * (new_size + new_size / 2));
	arr_copy(new_data, v->data, v->capacity);
	free(v->data);
	v->data = new_data;
	v->size = new_size;
	v->capacity = new_size + new_size / 2;
}
