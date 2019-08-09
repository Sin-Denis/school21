/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 14:12:01 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				main(void)
{
	int			num_roads;
	t_graph		*g;
	t_vector	**roads;
	t_vector	*distribution;
	int i;

	i = 0;
	g = graph_create();
	parse_main(g);
	if (g->nodes->size == 0)
		error_exit("Error");
	// ft_printf("hello\n");
	admonds_carp(g, 1);
	graph_print(g);
	num_roads = get_num_roads(g);
	roads = get_all_roads(g, num_roads);
	distribution = get_distribution(roads, g->num_ants, num_roads);
	output(g, roads, distribution, num_roads);
	vector_destroy(&distribution);
	while (i < num_roads)
		vector_destroy(&roads[i++]);
	free(roads);
	graph_destroy(&g);
	return (0);
}
