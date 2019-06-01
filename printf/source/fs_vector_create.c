/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_vector_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:52:46 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fs_vector		fs_vector_create(int size)
{
	t_fs_vector v;

	v.data = (t_fs *)malloc(sizeof(t_fs) * size);
	v.size = 0;
	v.capacity = size;
	return (v);
}
