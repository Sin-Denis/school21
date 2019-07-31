/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:57:18 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 10:28:58 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

static void copy(t_pair *dst, t_pair *src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		dst[i] = src[i];
}

static void grow(t_vector_pair *v)
{
	t_pair	*new_data;

	new_data = (t_pair *)malloc(sizeof(t_pair) * v->capacity * 2);
	copy(new_data, v->data, v->capacity);
	v->capacity *= 2;
	free(v->data);
	v->data = new_data;
}

void vector_pair_push_back(t_vector_pair *v, int first, long long second)
{
	if (v->size == v->capacity)
		grow(v);
	v->data[v->size].first = first;
	v->data[v->size].second = second;
	++v->size;
}