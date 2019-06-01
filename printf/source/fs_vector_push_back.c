/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_vector_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:53:57 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:33 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fs_vector_push_back(t_fs_vector *v, t_fs elem)
{
	if (v->size == v->capacity)
		fs_vector_resize(v, v->size * 2);
	fs_copy(&v->data[v->size], &elem);
	v->size++;
}
