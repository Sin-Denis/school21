/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/17 12:28:31 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	t_Graph	*g;

	Graph_create(&g);

	Graph_add_start_vert(g, "start");
	Graph_add_end_vert(g, "end");
	Graph_add_vert(g, "12");

	Graph_add_edge(g, "start", "12");
	Graph_add_edge(g, "start", "end");
	Graph_add_edge(g, "start", "start");
	Graph_add_edge(g, "12", "start");

	Graph_print(g);
	
	Graph_destroy(&g);
	return (0);
}
