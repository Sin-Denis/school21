/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:17:25 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/06 18:25:10 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int				ft_isnum(char *str)
{
	int			i;
	int			len;
	int			num;

	len = ft_strlen(str);
	num = ft_atoi(str);
	if (!ft_isdigit(str[0]) && len == 1)
		return (0);
	i = ft_count_digits(num) + (num < 0 ||
	(str[0] == '+' && ft_isdigit(str[1])) ? 1 : 0);
	if (i != len)
		return (0);
	return (1);
}
