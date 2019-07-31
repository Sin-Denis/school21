/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 15:49:15 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	
	t_graph *g;

	g = graph_create();
	graph_add_vert(g, "3");
	graph_add_start_vert(g, "start");
	graph_add_end_vert(g, "end");
	graph_add_vert(g, "4");
	graph_add_vert(g, "1");
	graph_add_vert(g, "2");
	graph_add_vert(g, "5");
	graph_add_vert(g, "6");
	graph_add_edge(g, 1, 4);
	graph_add_edge(g, 4, 1);
	graph_add_edge(g, 0, 3);
	graph_add_edge(g, 3, 0);
	graph_add_edge(g, 5, 3);
	graph_add_edge(g, 3, 5);
	graph_add_edge(g, 4, 6);
	graph_add_edge(g, 6, 4);
	graph_add_edge(g, 7, 6);
	graph_add_edge(g, 6, 7);
	graph_add_edge(g, 2, 7);
	graph_add_edge(g, 7, 2);
	graph_add_edge(g, 4, 5);
	graph_add_edge(g, 5, 4);
	graph_add_edge(g, 5, 2);
	graph_add_edge(g, 2, 5);
	graph_add_edge(g, 0, 1);
	graph_add_edge(g, 1, 0);
	graph_print(g);
	suurballe(g, 2);
	ft_printf("\n\n");
	graph_print(g);
	graph_destroy(&g);
	return (0);
}
