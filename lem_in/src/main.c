/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/07 10:55:20 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				main(void)
{
	// int			num_roads;
	t_graph		*g;
	// t_vector	**roads;
	// t_vector	*distribution;

	g = graph_create();
	g->num_ants = 198;
	graph_add_start_vert(g, "start");
	graph_add_end_vert(g, "end");
	graph_add_vert(g, "1");
	graph_add_vert(g, "2");
	graph_add_vert(g, "3");
	graph_add_vert(g, "4");
	graph_add_vert(g, "5");
	graph_add_vert(g, "6");
	graph_add_vert(g, "7");
	graph_add_vert(g, "8");
	graph_add_vert(g, "9");
	graph_add_vert(g, "10");
	graph_add_vert(g, "11");
	graph_add_vert(g, "12");
	graph_add_vert(g, "ad");
	graph_add_vert(g, "wall");

	graph_add_edge(g, 0, 2);
	graph_add_edge(g, 2, 3);
	graph_add_edge(g, 3, 4);
	graph_add_edge(g, 4, 9);
	graph_add_edge(g, 9, 1);
	graph_add_edge(g, 0, 5);
	graph_add_edge(g, 5, 6);
	graph_add_edge(g, 6, 8);
	graph_add_edge(g, 0, 7);
	graph_add_edge(g, 7, 8);
	graph_add_edge(g, 8, 9);
	graph_add_edge(g, 7, 10);
	graph_add_edge(g, 10, 11);
	graph_add_edge(g, 11, 12);
	graph_add_edge(g, 12, 1);
	graph_add_edge(g, 8, 13);
	graph_add_edge(g, 13, 1);
	graph_add_edge(g, 12, 14);
	graph_add_edge(g, 14, 1);
	graph_add_edge(g, 13, 15);
	graph_add_edge(g, 1, 15);
	
	suurballe(g);
	graph_print(g);
	
	// admonds_carp(g);
	// num_roads = get_num_roads(g);
	// roads = get_all_roads(g, num_roads);
	// distribution = get_distribution(roads, g->num_ants, num_roads);
	// output(g, roads, distribution, num_roads);
	graph_destroy(&g);
	return (0);
}
