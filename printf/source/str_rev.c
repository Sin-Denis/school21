/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:20:04 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:52 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		str_rev(t_string *s)
{
	int		i;
	char	tmp;

	i = 0;
	while (i * 2 < str_len(s))
	{
		tmp = s->data[i];
		s->data[i] = s->data[str_len(s) - i - 1];
		s->data[str_len(s) - i - 1] = tmp;
		++i;
	}
}
