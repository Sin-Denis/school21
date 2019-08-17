/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:04:55 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:41:07 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pair.h"

t_pair		*vector_pair_at(t_vector_pair *v, int idx)
{
	return (&v->data[idx]);
}

int			vector_pair_first(t_vector_pair *v, int idx)
{
	return (v->data[idx].first);
}

long long	vector_pair_second(t_vector_pair *v, int idx)
{
	return (v->data[idx].second);
}
