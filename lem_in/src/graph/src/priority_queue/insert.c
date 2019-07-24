/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:06:17 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 15:07:38 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Pq_insert(t_Priority_queue *q, t_Graph *g, int key)
{
	vector_push_back(q->arr, key);
	Pq_sift_up(q, g, key);
}
