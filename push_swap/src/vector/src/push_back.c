/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:37 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:30:36 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void	vector_push_back(t_vector *v, t_vector_type val)
{
	if (v->size == v->capacity)
		vector_resize(v, v->size);
	vector_set_elem(v, v->size, val);
	v->size++;
}
