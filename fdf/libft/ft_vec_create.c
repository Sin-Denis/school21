/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:45:18 by jblue-da          #+#    #+#             */
/*   Updated: 2019/05/13 12:18:36 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		ft_vec_create(int size)
{
	t_vector	v;

	v.data = (int *)malloc(sizeof(int) * size);
	v.size = 0;
	v.capacity = size;
	return (v);
}
