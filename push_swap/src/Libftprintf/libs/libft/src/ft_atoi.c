/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:35:29 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 17:49:39 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isdelimeter(int ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' \
	|| ch == '\v' || ch == '\r' || ch == '\f')
		return (1);
	return (0);
}

static int		ft_issign(int ch)
{
	if (ch == '-' || ch == '+')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	while (*str && ft_isdelimeter(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -1;
		else if (*str == '+')
			sign = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		number *= 10;
		number += *str;
		number -= '0';
		str++;
	}
	number *= sign;
	return (number);
}
