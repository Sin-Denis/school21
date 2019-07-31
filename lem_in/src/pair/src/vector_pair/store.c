/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:08:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 10:29:09 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

void	vector_pair_store(t_vector_pair *v, int idx, int first, long long second)
{
	v->data[idx].first = first;
	v->data[idx].second = second;	
}
