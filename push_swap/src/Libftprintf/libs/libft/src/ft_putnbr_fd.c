/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:00:11 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/12 14:57:01 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rec_putbnr(long long num, int fd)
{
	if (num > 0)
	{
		rec_putbnr(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (num == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num *= -1;
		}
		rec_putbnr(num, fd);
	}
}
