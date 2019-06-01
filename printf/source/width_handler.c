/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:39:51 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:55 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		width_insert_left(char **new_str, char *substr, int width, char c)
{
	int		i;
	char	sign;

	i = 0;
	sign = -1;
	if (*substr && c == '0' && (*substr == '-' || *substr == '+' ||
													*substr == ' '))
		sign = del_minus(&substr);
	while (width-- > 0)
		(*new_str)[i++] = c;
	while (*substr)
		(*new_str)[i++] = *substr++;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}

void		width_insert_right(char **new_str, char *substr, int width, char c)
{
	int		i;
	char	sign;

	i = 0;
	if (*substr && c == '0' && (*substr == '-' || *substr == '+' ||
													*substr == ' '))
		sign = del_minus(&substr);
	while (*substr)
		(*new_str)[i++] = *substr++;
	while (width-- > 0)
		(*new_str)[i++] = c;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}

void		width_insert(t_fs *form_string, char **substr)
{
	int		width;
	char	c;
	char	*new_str;

	c = ' ';
	width = form_string->width - ft_strlen(*substr);
	if (width <= 0)
		return ;
	new_str = ft_strnew((ft_strlen(*substr) + width));
	if (ft_strchr(form_string->flags, '0'))
		c = '0';
	if (ft_strchr(form_string->flags, '-'))
		width_insert_right(&new_str, *substr, width, c);
	else
		width_insert_left(&new_str, *substr, width, c);
	ft_strdel(substr);
	*substr = new_str;
}

void		s_get_width(t_fs *form_string, char **substr)
{
	int		i;
	char	*new_sub;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(*substr);
	new_sub = ft_strnew(ft_max(form_string->width, form_string->precision) + 1);
	c = ' ';
	if (ft_strchr(form_string->flags, '0'))
		c = '0';
	if (ft_strchr(form_string->flags, '-'))
		width_insert_right(&new_sub, *substr, form_string->width - len, c);
	else
		width_insert_left(&new_sub, *substr, form_string->width - len, c);
	if (form_string->precision == 0)
		while (i < form_string->width)
			new_sub[i++] = c;
	ft_strdel(substr);
	*substr = new_sub;
}
