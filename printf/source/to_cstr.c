/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_cstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:21:48 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:54 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*to_cstr(t_string *str)
{
	int		i;
	char	*res;

	i = -1;
	res = (char *)malloc(sizeof(char) * str_len(str));
	while (++i < str_len(str))
		res[i] = str->data[i];
	res[i] = 0;
	return (res);
}
