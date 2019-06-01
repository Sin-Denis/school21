/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sym_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:19:32 by jblue-da          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:06 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_sym_del(char **str, char c)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = NULL;
	while ((*str)[i])
	{
		if ((*str)[i] != c)
			ft_strpush(&new_str, (*str)[i]);
		++i;
	}
	free(*str);
	*str = new_str;
}
