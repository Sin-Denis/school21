/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:21:06 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 15:33:16 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/graph.h"

void        graph_destroy(t_graph **g)
{
    int i;

    i = -1;
    while (++i < (*g)->vert.size)
    {
        free((*g)->vert.data[i].adj);
    }
    free((*g)->vert.data);
}