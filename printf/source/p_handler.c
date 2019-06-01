/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:21:27 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:22 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_handler(t_fs *form_string, long long arg, char **format)
{
	char *substr;

	if (arg > 0)
		substr = ft_dec_to_hex(arg);
	else
		substr = ft_strdup("0");
	if (form_string->precision > 0)
		precision_insert(form_string, &substr);
	else if (form_string->precision == 0)
		substr = ft_strnew(0);
	if (ft_strchr(form_string->flags, '0'))
	{
		form_string->width -= 2;
		width_insert(form_string, &substr);
	}
	substr = ft_strjoin_free("0x", substr, 2);
	width_insert(form_string, &substr);
	*format = substr;
}
