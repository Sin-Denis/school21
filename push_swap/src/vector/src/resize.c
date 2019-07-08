/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:40 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:32:02 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

static int			min_val(int l, int r)
{
	return (l < r) ? l : r;
}

void				vector_resize(t_vector *v, int size)
{
	int				i;
	int				data_size;
	t_vector_type	*new_data;

	i = -1;
	data_size = min_val(size, vector_length(v));
	new_data = (t_vector_type *)malloc(sizeof(t_vector_type) *
	size * INCREASE_SIZE);
	while (++i < data_size)
		new_data[i] = vector_get_elem(v, i);
	while (i < size)
		new_data[i++] = 0;
	free(v->data);
	v->data = new_data;
	v->size = size;
	v->capacity = size * INCREASE_SIZE;
}
