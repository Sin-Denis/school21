/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:11:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/05 12:32:01 by jblue-da         ###   ########.fr       */
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

// static void		get_distribution_vals(t_vector *distribution, t_vector *get_attitude_roads, int num_ants)
// {
// 	int			common_vals;
// 	int			remainder_vals;

// 	common_vals = num_ants / get_attitude_roads->size;
// }

t_vector	*get_distribution(t_vector **roads, int num_ants, int num_roads)
{
	t_vector	*attitude_roads;
	t_vector	*distribution;

	attitude_roads = vector_create(num_roads);
	distribution = vector_create(num_roads);
	get_attitude_roads(roads, attitude_roads, num_roads);
	get_distribution_vals(distribution, attitude_roads, num_ants);
	return (attitude_roads);
}
