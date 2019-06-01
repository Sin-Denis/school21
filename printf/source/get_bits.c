/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:20:15 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 18:47:45 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*get_the_bits(long double arg)
{
	int			i;
	int			byte;
	t_bignum	*num;

	i = 62;
	if (arg < 0)
		arg *= -1.0;
	t.d_num = (long double)arg;
	num = big_num_create();
	str_pushchar(&num->int_part, (t.t_double.mantissa >> 63 & 1) + 48);
	byte = 0;
	while (i >= 0)
	{
		byte = t.t_double.mantissa >> i & 1;
		str_pushchar(&num->frac_part, byte + 48);
		--i;
	}
	if (arg > 0)
	{
		if (t.t_double.exponent - 16383 > 0)
			pos_pow(&num, t.t_double.exponent - 16383, bin_mult);
		else
			pos_pow(&num, t.t_double.exponent - 16383, bin_div);
	}
	return (num);
}
