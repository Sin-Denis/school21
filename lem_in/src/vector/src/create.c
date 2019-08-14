/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:27 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 09:57:24 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

t_vector		*vector_create(int size)
{
	int			i;
	t_vector	*v;

	i = 0;
	v = (t_vector *)malloc(sizeof(t_vector));
	if (size == 0)
	{
		v->data = (t_vector_type *)malloc(sizeof(t_vector_type) * 10);
		v->size = 0;
		v->capacity = 10;
	}
	else
	{
		v->data = (t_vector_type *)malloc(sizeof(t_vector_type) *
		size * INCREASE_SIZE);
		v->size = size;
		v->capacity = size * INCREASE_SIZE;
	}
	while (i < size)
	{
		v->data[i] = 0;
		++i;
	}
	return (v);
}
