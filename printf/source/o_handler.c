/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:33:32 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:21 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_handler(t_fs *form_string, unsigned long long arg, char **format)
{
	char *substr;

	substr = NULL;
	u_cast(form_string, &arg);
	if (arg > 0)
		substr = dec_to_octal(arg);
	else
		substr = ft_strdup("0");
	if (form_string->precision == 0 && !ft_strchr(form_string->flags, '#')
															&& arg == 0)
		substr = ft_strnew(0);
	if (ft_strchr(form_string->flags, '#') && form_string->precision
									<= (int)ft_strlen(substr) && arg != 0)
		substr = ft_strjoin_free("0", substr, 2);
	precision_insert(form_string, &substr);
	width_insert(form_string, &substr);
	*format = substr;
}
