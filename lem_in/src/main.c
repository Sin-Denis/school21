/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/18 10:56:07 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	t_Graph	*g;

	Graph_create(&g);

	Graph_add_vert(g, "3");
	Graph_add_start_vert(g, "start");
	Graph_add_end_vert(g, "end");
	Graph_add_vert(g, "4");
	Graph_add_vert(g, "1");
	Graph_add_vert(g, "2");
	Graph_add_vert(g, "5");
	Graph_add_vert(g, "6");

	Graph_add_edge(g, "start", "1");
	Graph_add_edge(g, "3", "4");
	Graph_add_edge(g, "2", "4");
	Graph_add_edge(g, "1", "5");
	Graph_add_edge(g, "6", "5");
	Graph_add_edge(g, "end", "6");
	Graph_add_edge(g, "1", "2");
	Graph_add_edge(g, "2", "end");
	Graph_add_edge(g, "3", "start");

	Graph_print(g);
	Graph_destroy(&g);
	return (0);
}
