/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:24:30 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 15:59:21 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

t_Vertex	*Graph_get_vert(t_Graph *g, size_t id)
{
	return (Hash_table_at_num(g->table, id));
}

int			Graph_get_idx(t_Graph *g, char *key)
{
	return (Hash_table_idx(g->table, key));
}
