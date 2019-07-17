/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:27:05 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/17 12:04:58 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void    Vert_vector_destroy(t_Vert_vector **v)
{
    int i;

    i = -1;
    while (++i < (*v)->size)
    {
        if ((*v)->data[i].adj != NULL)
            vector_destroy(&(*v)->data[i].adj);
    }
    free((*v)->data);
    free((*v));
    *v = NULL;
}
