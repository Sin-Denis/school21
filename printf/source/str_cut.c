/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:14:00 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:47 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string		str_cut(t_string *str, int start, int end)
{
	t_string	new_str;

	new_str = str_create_size(10);
	start--;
	while (++start < end && start < str_len(str))
		str_pushchar(&new_str, str_at(str, start));
	return (new_str);
}
