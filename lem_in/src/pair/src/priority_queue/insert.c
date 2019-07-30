/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:59:58 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 11:02:13 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

void	pq_insert(t_priority_queue *q, int first, int second)
{
	vector_pair_push_back(q->v, first, second);
	pq_sift_up(q, vector_pair_len(q->v) - 1);
}
