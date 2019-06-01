/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:17:11 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:20 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			lf_handler(t_fs *form_string, long double arg, char **format)
{
	char		sign;
	t_bignum	*num;
	char		*str;

	sign = f_get_sign(form_string, arg);
	if (form_string->precision == -1)
		form_string->precision = 6;
	num = get_the_bits(arg);
	bin_to_dec(num);
	rround(&num, form_string->precision);
	str = put_bignum_strings_into_one(num, form_string);
	if (sign == '-')
		add_sign(&str, '-');
	else if (sign == '+')
		add_sign(&str, '+');
	if (ft_strchr(form_string->flags, ' ') && sign != '-')
		add_sign(&str, ' ');
	width_insert(form_string, &str);
	if (ft_strchr(form_string->flags, '#') && form_string->precision == 0)
		*format = ft_strjoin_free(str, ".", 1);
	else
		*format = str;
}
