/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:33:42 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:36:54 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*bin_mult(t_bignum *l)
{
	t_bignum	*res;
	t_string	new_frac_part;

	res = big_num_create();
	res->sign = l->sign;
	new_frac_part = str_cut(&l->frac_part, 1, str_len(&l->frac_part));
	str_push_cs(&res->frac_part, &new_frac_part);
	str_push_cs(&res->int_part, &l->int_part);
	str_pushchar(&res->int_part, str_at(&l->frac_part, 0));
	if (str_len(&res->int_part) == 0)
		str_pushchar(&res->int_part, '0');
	if (str_len(&res->frac_part) == 0)
		str_pushchar(&res->frac_part, '0');
	str_destroy(&new_frac_part);
	return (res);
}
