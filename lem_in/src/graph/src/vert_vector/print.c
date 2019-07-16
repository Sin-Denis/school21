/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:49:42 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 11:53:06 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Vert_vector_print(t_Vert_vector *v)
{
    int	i;

    i = -1;
	while (++i < v->size)
		ft_printf("Vert_id: %s\n", v->data[i].id);
}
