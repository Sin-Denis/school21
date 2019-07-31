/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:48:37 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 11:16:56 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

t_priority_queue		*pq_create(void)
{
	t_priority_queue	*q;

	q = (t_priority_queue *)malloc(sizeof(t_priority_queue));
	q->v = vector_pair_create(0);
	return (q);
}

void					pq_destroy(t_priority_queue **q)
{
	vector_pair_destroy(&(*q)->v);
	free(*q);
	(*q) = NULL;
}
