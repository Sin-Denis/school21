/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:33:50 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:20 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum	*dec_div(t_bignum *n)
{
	t_bignum	*res;
	int			i;

	i = -1;
	res = big_num_create();
	res->sign = n->sign;
	if (n->int_part.data[0] == '1')
	{
		big_num_destroy(&res);
		res = big_num_create_by_str(n->sign, "0", "5");
		return (res);
	}
	str_pushchar(&res->int_part, '0');
	while (++i < n->frac_part.size)
		if (i > 0)
			str_pushchar(&res->frac_part, ((n->frac_part.data[i] - 48) +
				(n->frac_part.data[i - 1] - 48) % 2 * 10) / 2 + 48);
		else
			str_pushchar(&res->frac_part, (n->frac_part.data[i] - 48) / 2 + 48);
	str_pushchar(&res->frac_part, (n->frac_part.data[i - 1]));
	return (res);
}
