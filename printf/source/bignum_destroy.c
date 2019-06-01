/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:33:33 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:36:55 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	big_num_destroy(t_bignum **num)
{
	str_destroy(&(*num)->int_part);
	str_destroy(&(*num)->frac_part);
	free(*num);
	*num = NULL;
}
