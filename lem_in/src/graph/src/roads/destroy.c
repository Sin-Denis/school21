/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:27:29 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 10:42:20 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Roads_destroy(t_Roads **r)
{
	int	i;

	i = -1;
	while ((size_t)++i < (*r)->size)
		vector_destroy(&(*r)->roads[i]);
	free((*r)->roads);
	free(*r);
	*r = NULL;
}
