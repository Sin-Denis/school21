/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_road.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:33:21 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 11:05:40 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Roads_add_road(t_Roads *r, int idx, t_vector *v)
{
	vector_copy(r->roads[idx], v);
}

static void grow(t_Roads *r)
{
	t_vector **v;
	int i;

	i = -1;
	v = (t_vector **)malloc(sizeof(t_vector *) * r->capacity * 2);
	while ((size_t)++i < r->size)
		v[i] = r->roads[i];
	free(r->roads);
	r->roads = v;
}

void	Roads_push_road(t_Roads *r, t_vector *v)
{
	if (r->size == r->capacity)
		grow(r);
	r->roads[r->size] = vector_create(0);
	vector_copy(r->roads[r->size], v);
	++r->size;
}
