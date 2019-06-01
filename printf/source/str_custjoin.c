/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_custjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:13:18 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:46 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string		str_custjoin(t_string *l, t_string *r)
{
	t_string	res;

	res = str_create_custstr(l);
	str_push_cs(&res, r);
	return (res);
}
