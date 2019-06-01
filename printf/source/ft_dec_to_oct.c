/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:32:47 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:37 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*dec_to_octal(unsigned long long n)
{
	int		octal_num[100];
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	str = NULL;
	while (n != 0)
	{
		octal_num[i] = n % 8;
		n = n / 8;
		i++;
	}
	str = ft_strnew(i);
	while (i--)
		str[j++] = octal_num[i] + 48;
	return (str);
}
