/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:03:10 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:36 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_dec_to_hex(unsigned long long n)
{
	char	str[100];
	int		temp;
	int		i;
	char	*res;

	i = 0;
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			str[i++] = temp + 48;
		else
			str[i++] = temp + 87;
		n = n / 16;
	}
	str[i] = '\0';
	res = ft_rev_str(str);
	return (res);
}
