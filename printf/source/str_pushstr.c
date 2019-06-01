/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pushstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:18:51 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:51 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pushstr(t_string *s, char *str)
{
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(str);
	if (s->capacity < s->size + len)
		str_resize(s, (s->size + len) * 2);
	while (++i < len)
		str_pushchar(s, str[i]);
}
