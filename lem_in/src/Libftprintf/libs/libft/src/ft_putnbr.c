/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:04:39 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/12 14:54:13 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rec_putbnr(long long num)
{
	if (num > 0)
	{
		rec_putbnr(num / 10);
		ft_putchar(num % 10 + '0');
	}
}

void			ft_putnbr(int n)
{
	long long	num;

	num = n;
	if (num == 0)
		ft_putchar('0');
	else
	{
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		rec_putbnr(num);
	}
}
