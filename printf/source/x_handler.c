/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:55:41 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:56 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		x_handler(t_fs *form_string,
						unsigned long long arg, char **format)
{
	char	*substr;

	u_cast(form_string, &arg);
	if (arg > 0)
		substr = ft_dec_to_hex(arg);
	else if (form_string->precision != 0)
		substr = ft_strdup("0");
	if (form_string->precision == 0 && arg == 0)
		substr = ft_strnew(0);
	else if (form_string->precision > 0)
		precision_insert(form_string, &substr);
	if (ft_strchr(form_string->flags, '#') && arg != 0)
	{
		if (ft_strchr(form_string->flags, '0'))
		{
			form_string->width -= 2;
			width_insert(form_string, &substr);
		}
		substr = ft_strjoin_free("0x", substr, 2);
	}
	width_insert(form_string, &substr);
	if (form_string->type == 'X')
		ft_toupper(&substr);
	*format = substr;
}
