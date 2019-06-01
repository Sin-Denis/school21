/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_create_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:11:16 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:46 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string		str_create_str(char *s)
{
	t_string	str;
	int			len;
	int			i;

	i = -1;
	len = ft_strlen(s);
	str.data = (char *)malloc(sizeof(char) * len * 3 / 2);
	str.size = len;
	str.capacity = len * 3 / 2;
	while (++i < len)
		str.data[i] = s[i];
	return (str);
}
