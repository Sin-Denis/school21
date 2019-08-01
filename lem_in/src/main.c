/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/01 10:44:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	
	t_graph *g;

	g = graph_create();
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
	graph_print(g);
	dijkstra(g);
	// suurballe(g, 1);
	ft_printf("\n\n");
	graph_print(g);
	graph_destroy(&g);
	return (0);
}
