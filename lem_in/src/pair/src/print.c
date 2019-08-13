/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:12:02 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/13 11:58:53 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pair.h"

void		vector_pair_print(t_vector_pair *v)
{
	size_t	i;

	i = 0;
	while (i < v->size)
	{
		if (i + 1 == v->size)
			ft_printf("(%d: %d)\n", v->data[i].first, v->data[i].second);
		else
			ft_printf("(%d: %d), ", v->data[i].first, v->data[i].second);
		++i;
	}
}
