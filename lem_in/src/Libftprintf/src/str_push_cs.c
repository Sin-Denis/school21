/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:16:52 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:50 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	str_push_cs(t_string *l, t_string *r)
{
	int i;

	i = -1;
	while (++i < str_len(r))
		str_pushchar(l, str_at(r, i));
}
