/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:14:17 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 13:46:45 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

void		vector_pair_del(t_vector_pair *v, int key)
{
	size_t	i;

	i = 0;
	while (v->data[i].first != key)
		++i;
	while (i + 1 < v->size)
	{
		v->data[i] = v->data[i + 1];
		++i;
	}
	--v->size;
}
