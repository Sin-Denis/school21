/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:44:19 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 14:46:14 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

int	vector_get_sum(t_vector *v, int start, int end)
{
	int res;

	res = 0;
	while (start < end)
		res += v->data[start++];
	return (res);
}
