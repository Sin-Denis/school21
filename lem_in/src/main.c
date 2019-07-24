/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 16:04:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			main(void)
{
	t_Graph	*g;
	t_Roads *r;

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
	Graph_set_weight(g, 49, 3, 2);
	Graph_print(g);

	t_Priority_queue *q;
	Pq_create(&q);

	Pq_insert(q, g, Hash_table_idx(g->table, "start"));
	Pq_insert(q, g, Hash_table_idx(g->table, "end"));
	Pq_insert(q, g, Hash_table_idx(g->table, "1"));
	Pq_insert(q, g, Hash_table_idx(g->table, "6"));
	
	ft_printf("%d\n", Pq_min(q));

	Pq_destroy(&q);
	Graph_destroy(&g);
	return (0);
}
