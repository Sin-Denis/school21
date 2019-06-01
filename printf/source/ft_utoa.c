/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:17:54 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:08 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_str_len(unsigned long long n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_utoa(unsigned long long n)
{
	unsigned long long	cpy_n;
	size_t				len;
	char				*new_str;

	len = ft_str_len(n);
	cpy_n = n;
	if (!(new_str = ft_strnew(len)))
		return (0);
	new_str[--len] = cpy_n % 10 + '0';
	while (cpy_n /= 10)
		new_str[--len] = cpy_n % 10 + '0';
	return (new_str);
}
