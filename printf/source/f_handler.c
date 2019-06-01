/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:10:34 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 18:54:07 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*put_bignum_strings_into_one(t_bignum *num,
											t_fs *form_string)
{
	char	*str;
	char	*temp;
	char	*temp2;
	char	*temp3;

	if (form_string->precision == 0)
		str = cust_strdup(&num->int_part);
	else
	{
		temp = cust_strjoin_left(&num->int_part, ".");
		temp2 = cust_strdup(&num->frac_part);
		temp3 = ft_strsub(temp2, 0, form_string->precision);
		str = ft_strjoin_free(temp, temp3, 3);
		ft_strdel(&temp2);
	}
	big_num_destroy(&num);
	return (str);
}

static void		add_sign_float(char sign, char **str, t_fs *form_string)
{
	if (sign == '-')
		add_sign(str, '-');
	else if (sign == '+')
		add_sign(str, '+');
	if (ft_strchr(form_string->flags, ' ') && sign != '-')
		add_sign(str, ' ');
}

void			f_handler(t_fs *form_string, double arg, char **format)
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
	add_sign_float(sign, &str, form_string);
	width_insert(form_string, &str);
	if (ft_strchr(form_string->flags, '#') && form_string->precision == 0)
		*format = ft_strjoin_free(str, ".", 1);
	else
		*format = str;
}
