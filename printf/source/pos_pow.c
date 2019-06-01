/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_pow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:33:58 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:24 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pos_pow(t_bignum **n, int power, t_bignum *(*f)(t_bignum *))
{
	t_bignum	*tmp;
	int			i;

	i = -1;
	while (++i < ft_abs(power))
	{
		tmp = (*f)(*n);
		big_num_destroy(n);
		*n = tmp;
	}
}
