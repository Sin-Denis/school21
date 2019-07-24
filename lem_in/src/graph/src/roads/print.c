/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:45:14 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 10:53:22 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Roads_print(t_Roads *r)
{
	int i;

	i = -1;
	while ((size_t)++i < r->size)
	{
		ft_printf("Road %d: ", i);
		vector_print(r->roads[i]);
		ft_printf("\n");
	}
}
