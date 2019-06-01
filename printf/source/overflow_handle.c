/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:41:37 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:22 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				overflow_handle(char *str)
{
	int			i;
	long long	num;

	if (str == NULL)
		return (0);
	i = 0;
	num = 0;
	while (str[i] && num <= 2147483647)
	{
		num *= 10;
		num += str[i] - 48;
		++i;
	}
	if (num > 2147483647)
		num = 0;
	return (num);
}
