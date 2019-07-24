/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:22:19 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 15:54:50 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Pq_create(t_Priority_queue **q)
{
	(*q) = (t_Priority_queue *)malloc(sizeof(t_Priority_queue));
	(*q)->arr = vector_create(0);
}