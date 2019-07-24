/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:24:46 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 13:24:46 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Graph_add_vert(t_Graph *g, char *name)
{
	Hash_table_key_add(g->table, name);
	++g->size;
}

void	Graph_add_start_vert(t_Graph *g, char *name)
{
	Hash_table_key_add(g->table, name);
	g->start_id = ft_strdup(name);
	++g->size;
}

void	Graph_add_end_vert(t_Graph *g, char *name)
{
	Hash_table_key_add(g->table, name);
	g->end_id = ft_strdup(name);
	++g->size;
}
