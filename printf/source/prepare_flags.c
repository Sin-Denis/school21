/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:51:22 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 18:38:04 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prepare_item_flags(t_fs *form_string)
{
	if (ft_strchr(form_string->flags, ' ') &&
		(ft_strchr(form_string->flags, '+') || form_string->type == 's'))
		ft_sym_del(&form_string->flags, ' ');
	if (ft_strchr(form_string->flags, '+') &&
		!ft_strchr("idf", form_string->type))
		ft_sym_del(&form_string->flags, '+');
	if (ft_strchr(form_string->flags, '-') && form_string->width == 0)
		ft_sym_del(&form_string->flags, '-');
	if (ft_strchr(form_string->flags, '0') &&
		(ft_strchr(form_string->flags, '-') || (form_string->precision >= 0
		&& (form_string->type != 'f') && form_string->type != 'c'
		&& form_string->type != 's' && form_string->type != '%')))
		ft_sym_del(&form_string->flags, '0');
	if (ft_strchr(form_string->flags, '#') &&
		!ft_strchr("xoXf", form_string->type))
		ft_sym_del(&form_string->flags, '#');
}
