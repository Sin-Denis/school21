/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:42:44 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:14 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_precision(char **str)
{
	char	*str_precision;
	int		num_precision;

	str_precision = NULL;
	if (**str != '.')
		return (-1);
	move_char_pointer(str);
	if (**str == '-')
		return (0);
	while (**str && ft_isdigit(**str))
	{
		ft_strpush(&str_precision, **str);
		move_char_pointer(str);
	}
	num_precision = overflow_handle(str_precision);
	ft_strdel(&str_precision);
	return (num_precision);
}
