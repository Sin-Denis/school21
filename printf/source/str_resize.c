/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:19:28 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:52 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		str_resize(t_string *s, int new_size)
{
	char	*new_data;
	int		i;

	i = -1;
	new_data = ft_strnew(new_size - 1);
	while (++i < s->size)
		new_data[i] = s->data[i];
	free(s->data);
	s->data = new_data;
	s->capacity = new_size;
}
