/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:08:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/22 11:08:49 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_pair.h"

void	vector_pair_store(t_vector_pair *v, int idx, int first, int second)
{
	v->data[idx].first = first;
	v->data[idx].second = second;	
}
