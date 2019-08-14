/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:39:22 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 17:50:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_num(long long num)
{
	size_t		len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void		convert(char **str, long long num, size_t index)
{
	if (num == 0)
		(*str)[index] = num % 10 + '0';
	while (num > 0)
	{
		(*str)[index] = num % 10 + '0';
		num /= 10;
		index--;
	}
}

char			*ft_itoa(int n)
{
	long long	num;
	char		*str;
	int			sign;
	size_t		len;

	len = 0;
	sign = 0;
	num = (long long)n;
	if (num < 0)
	{
		sign--;
		num *= -1;
		len++;
	}
	len += len_num(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	str[len] = 0;
	convert(&str, num, len - 1);
	return (str);
}
