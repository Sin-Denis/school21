/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:44:04 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:17 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		get_type(char **str)
{
	char	type;

	type = 0;
	if (ft_isflag(**str) || **str == '%')
	{
		type = **str;
		move_char_pointer(str);
	}
	return (type);
}
