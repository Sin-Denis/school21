/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:35:19 by jblue-da          #+#    #+#             */
/*   Updated: 2019/05/13 12:17:57 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int power)
{
	if (power == 0)
		return (1);
	if (power % 2 == 0)
		return (ft_pow(n * n, power / 2));
	return (n * ft_pow(n, power - 1));
}
