/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:33:27 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:22 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			frac_dec_mult(t_string *n, t_string *res)
{
	int			i;
	char		rem;
	char		num_res;

	rem = 0;
	i = str_len(n) - 1;
	while (i >= 0)
	{
		num_res = (rem + (str_at(n, i) - '0') * 2) % 10 + '0';
		rem = (rem + ((str_at(n, i) - '0') * 2)) / 10;
		str_pushchar(res, num_res);
		--i;
	}
	str_rev(res);
	return (rem);
}

void			int_dec_mult(t_string *n, t_string *res, char rem)
{
	int			i;
	int			j;
	char		num_res;

	j = 0;
	i = str_len(n);
	while (--i >= 0)
	{
		num_res = (rem + (str_at(n, i) - 48) * 2) % 10 + '0';
		rem = (rem + (str_at(n, i) - 48) * 2) / 10;
		str_pushchar(res, num_res);
	}
	if (rem > 0)
		str_pushchar(res, rem + '0');
	str_rev(res);
}

t_bignum		*dec_mult(t_bignum *n)
{
	t_bignum	*res;
	char		rem;

	res = big_num_create();
	res->sign = n->sign;
	rem = frac_dec_mult(&n->frac_part, &res->frac_part);
	int_dec_mult(&n->int_part, &res->int_part, rem);
	return (res);
}
