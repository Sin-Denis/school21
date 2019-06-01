/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:41:44 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:26 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		s_get_precision(t_fs *form_string, char **substr)
{
	int		i;
	int		precision;
	char	*new_substr;

	precision = form_string->precision;
	i = 0;
	new_substr = ft_strnew(precision);
	while (precision-- && (*substr)[i])
	{
		new_substr[i] = (*substr)[i];
		i++;
	}
	ft_strdel(substr);
	*substr = new_substr;
}

void		precision_insert(t_fs *form_string, char **substr)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	len = ft_strlen(*substr);
	temp = ft_strnew(form_string->precision + 1);
	while (i < form_string->precision - len)
	{
		temp[i] = '0';
		i++;
	}
	temp = ft_strjoin_free(temp, *substr, 3);
	*substr = temp;
}
