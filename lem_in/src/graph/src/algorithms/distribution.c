/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:11:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/07 16:58:24 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		get_attitude_roads(t_vector **roads, t_vector *attitude_roads, int num_roads)
{
	int		i;
	int		len_big_road;

	i = num_roads - 1;
	len_big_road = roads[i]->size;
	vector_set_elem(attitude_roads, i, 1);
	while (--i >= 0)
		vector_set_elem(attitude_roads, i, len_big_road - roads[i]->size + 1);
}

static void		get_distribution_vals(t_vector *distribution, t_vector *attitude_roads, int num_ants)
{
	int			i;
	int			add_val;
	int			rem_val;

	i = -1;
	while (num_ants > 0 && ++i < distribution->size)
	{
		if (num_ants >= vector_get_elem(attitude_roads, i))
		{
			vector_set_elem(distribution, i, vector_get_elem(attitude_roads, i));
			num_ants -= vector_get_elem(attitude_roads, i);
		}
		else
		{
			vector_set_elem(distribution, i, num_ants);
			num_ants = 0;
		}
	}
	i = -1;
	add_val = num_ants / attitude_roads->size;
	rem_val = num_ants % attitude_roads->size;
	while (num_ants > 0 && ++i < distribution->size)
	{
		distribution->data[i] += add_val;
		if (i < rem_val)
			++distribution->data[i];
	}
}

t_vector	*get_distribution(t_vector **roads, int num_ants, int num_roads)
{
	t_vector	*attitude_roads;
	t_vector	*distribution;

	attitude_roads = vector_create(num_roads);
	distribution = vector_create(num_roads);
	get_attitude_roads(roads, attitude_roads, num_roads);
	get_distribution_vals(distribution, attitude_roads, num_ants);
	vector_destroy(&attitude_roads);
	return (distribution);
}
