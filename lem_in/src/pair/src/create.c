/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:50:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:42:35 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pair.h"

static void			zero_vector(t_vector_pair *v)
{
	size_t			i;

	i = 0;
	while (i < v->size)
	{
		v->data[i].first = 0;
		v->data[i].second = 0;
		++i;
	}
}

t_vector_pair		*vector_pair_create(int size)
{
	t_vector_pair	*v;

	v = (t_vector_pair *)malloc(sizeof(t_vector_pair));
	if (size == 0)
	{
		v->data = (t_pair *)malloc(sizeof(t_pair) * 10);
		v->size = 0;
		v->capacity = 10;
	}
	else
	{
		v->data = (t_pair *)malloc(sizeof(t_pair) * size * 2);
		v->size = size;
		v->capacity = size * 2;
	}
	zero_vector(v);
	return (v);
}

t_pair				*pair_create(int first, long long second)
{
	t_pair			*new_pair;

	new_pair = (t_pair*)malloc(sizeof(t_pair));
	new_pair->first = first;
	new_pair->second = second;
	return (new_pair);
}
