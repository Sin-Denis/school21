/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:18:25 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/06 18:18:41 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int		ft_count_digits(int n)
{
	int i;

	i = 1;
	while ((n = n / 10) != 0)
		i++;
	return (i);
}
