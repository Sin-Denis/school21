/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:24:46 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:55 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unum_insert(char **substr, unsigned
						long long arg)
{
	char	*number;

	number = ft_utoa(arg);
	*substr = number;
}

void		u_cast(t_fs *form_string, unsigned long long *arg)
{
	if (form_string->size == NULL)
		*arg = (unsigned int)*arg;
	else if (ft_strcmp(form_string->size, "l") == 0)
		*arg = (unsigned long)*arg;
	else if (ft_strcmp(form_string->size, "hh") == 0)
		*arg = (unsigned char)*arg;
	else if (ft_strcmp(form_string->size, "h") == 0)
		*arg = (unsigned short int)*arg;
}

void		u_handler(t_fs *form_string, unsigned long long arg, char **format)
{
	char	*substr;

	substr = NULL;
	u_cast(form_string, &arg);
	unum_insert(&substr, arg);
	if (form_string->precision == 0 && arg == 0)
		substr = ft_strnew(0);
	precision_insert(form_string, &substr);
	width_insert(form_string, &substr);
	*format = substr;
}
