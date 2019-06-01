/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_create_custstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:08:51 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:43 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string		str_create_custstr(t_string *cs)
{
	int			i;
	t_string	res;

	i = -1;
	res.capacity = str_len(cs) + str_len(cs) * 3 / 2;
	res.data = (char *)malloc(res.capacity * sizeof(char));
	res.size = str_len(cs);
	while (++i < res.size)
		res.data[i] = cs->data[i];
	return (res);
}
