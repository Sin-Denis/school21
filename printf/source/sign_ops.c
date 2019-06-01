/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:37:39 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:38 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		f_get_sign(t_fs *form_string, long double arg)
{
	char	sign;

	sign = 0;
	if (arg >= 0 && ft_strchr(form_string->flags, '+'))
		sign = '+';
	else if (arg > 0)
		sign = 0;
	else if (arg < 0)
		sign = '-';
	return (sign);
}

char		get_sign(t_fs *form_string, long long arg)
{
	char	sign;

	sign = 0;
	if (arg >= 0 && ft_strchr(form_string->flags, '+'))
		sign = '+';
	else if (arg > 0)
		sign = 0;
	else if (arg < 0)
		sign = '-';
	return (sign);
}

void		add_sign(char **str, char sign)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*str) + 1;
	new_str = ft_strnew(len);
	new_str[0] = sign;
	while (++i < len)
		new_str[i] = (*str)[i - 1];
	ft_strdel(str);
	*str = new_str;
}

char		del_minus(char **str)
{
	int		i;
	int		len;
	char	sign;

	sign = **str;
	i = -1;
	len = ft_strlen(*str) - 1;
	while (++i < len)
		(*str)[i] = (*str)[i + 1];
	(*str)[i] = 0;
	return (sign);
}
