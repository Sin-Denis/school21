/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pushchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:18:14 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:51 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pushchar(t_string *s, char c)
{
	if (s->size == s->capacity)
		str_resize(s, s->size + 25);
	s->data[s->size] = c;
	s->size++;
}
