/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:34:02 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:36 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				find_digit(t_string *s, int start)
{
	while (start < str_len(s))
		if (s->data[start++] > '0')
			return (1);
	return (0);
}

static void		put_zeros(int precision, t_string *str)
{
	if (precision > str->size)
		while (precision != str->size)
			str_pushchar(str, '0');
}

void			rround(t_bignum **num, int precision)
{
	t_bignum *temp;

	put_zeros(precision, &(*num)->frac_part);
	if (((*num)->frac_part.size > precision &&
		(*num)->frac_part.data[precision] <= '4') ||
			!find_digit(&(*num)->frac_part, precision + 1))
		return ;
	if (precision == 0)
	{
		(*num)->int_part.data[(*num)->int_part.size - 1]++;
		return ;
	}
	temp = big_num_create();
	str_pushchar(&temp->int_part, '0');
	while (precision-- > 1)
		str_pushchar(&temp->frac_part, '0');
	str_pushchar(&temp->frac_part, '1');
	*num = dec_sum(*num, temp, 3);
}
