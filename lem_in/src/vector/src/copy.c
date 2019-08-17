/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:58:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 16:00:39 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void	vector_copy(t_vector *dst, t_vector *src)
{
	int	*new_data;
	int	i;

	i = -1;
	if (dst == src)
		return ;
	free(dst->data);
	new_data = (int *)malloc(sizeof(int) * src->capacity);
	while (++i < src->size)
		new_data[i] = src->data[i];
	dst->data = new_data;
	dst->size = src->size;
	dst->capacity = src->capacity;
}
