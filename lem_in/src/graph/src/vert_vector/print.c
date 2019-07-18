/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:49:42 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/18 09:51:24 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Vert_vector_print(t_Vert_vector *v)
{
    size_t	i;

    i = 0;
	while (i < v->size)
    {
        ft_printf("Vert_id: %s\n", v->data[i].id);
        ++i;
    }
}
