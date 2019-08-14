/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:44:46 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/13 11:58:49 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pair.h"

static void	decrease(t_vector_pair *v)
{
	size_t	i;
	t_pair 	*new_data;

	i = 0;
	new_data = (t_pair *)malloc(sizeof(t_pair) * v->size * 2);
	while (i < v->size)
	{
		new_data[i] = v->data[i];
		++i;
	}
	free(v->data);
	v->data = new_data;
	v->capacity = v->size * 2;
}

void		vector_pair_pop_back(t_vector_pair *v)
{
	--v->size;
	if (v->size * 4 <= v->capacity)
		decrease(v);
}
