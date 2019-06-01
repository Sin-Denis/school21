/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_create_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:09:39 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:45 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string		str_create_size(int size)
{
	t_string	str;

	str.data = ft_strnew(size - 1);
	str.size = 0;
	str.capacity = size;
	return (str);
}
