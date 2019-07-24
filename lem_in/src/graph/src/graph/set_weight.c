/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:23:29 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/23 10:13:21 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static int		get_idx(t_vector_pair *v, int first)
{
    int			i;

    i = -1;
    while (++i < vector_pair_len(v))
    {
        if (vector_pair_first(v, i) == first )
            return i;
    }
    return (-1);
}

/* Нужно будет поменять хранение смежных вершин на AVL дерево либо на красно черное дерево */
void			Graph_set_weight(t_Graph *g, size_t id1, size_t id2, int weight)
{
	t_Vertex	*v1;

	v1 = Vert_vector_at(g->table->data, id1);
	vector_pair_store(v1->adj, get_idx(v1->adj, id2), id2, weight);
}
