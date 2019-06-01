/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_create_by_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:33:30 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:36:58 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*big_num_create_by_str(char sign,
					char *int_part, char *frac_part)
{
	t_bignum	*num;

	num = (t_bignum *)malloc(sizeof(t_bignum));
	num->sign = sign;
	num->int_part = str_create_str(int_part);
	num->frac_part = str_create_str(frac_part);
	return (num);
}
