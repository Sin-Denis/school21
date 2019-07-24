/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:18:33 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 10:49:14 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void Roads_create(t_Roads **r)
{
	(*r) = (t_Roads *)malloc(sizeof(t_Roads));
	(*r)->roads = (t_vector **)malloc(sizeof(t_vector *) * 5);
	(*r)->size = 0;
	(*r)->capacity = 5;
}
