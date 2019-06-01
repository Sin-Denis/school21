/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:49:38 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:29 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prepare_item_size_n(t_fs *form_string)
{
	char	*new_str;

	new_str = NULL;
	if (ft_strncmp(form_string->size, "ll", 2) == 0)
		new_str = ft_strdup("ll");
	else if (ft_strncmp(form_string->size, "l", 1) == 0)
		new_str = ft_strdup("l");
	else if (ft_strncmp(form_string->size, "hh", 2) == 0)
		new_str = ft_strdup("hh");
	else if (ft_strncmp(form_string->size, "h", 1) == 0)
		new_str = ft_strdup("h");
	ft_strdel(&form_string->size);
	form_string->size = new_str;
}

void		prepare_item_size_f(t_fs *form_string)
{
	char	*new_str;

	new_str = NULL;
	if (ft_strncmp(form_string->size, "l", 1) == 0)
		new_str = ft_strdup("l");
	else if (ft_strncmp(form_string->size, "L", 1) == 0)
		new_str = ft_strdup("L");
	ft_strdel(&form_string->size);
	form_string->size = new_str;
}

void		prepare_item_size(t_fs *form_string)
{
	char	*new_size;

	new_size = NULL;
	if (form_string->size == NULL)
		return ;
	if (!ft_strchr("diouxXf", form_string->type))
	{
		ft_strdel(&form_string->size);
		return ;
	}
	if (ft_strchr("diouxX", form_string->type))
		prepare_item_size_n(form_string);
	else
		prepare_item_size_f(form_string);
}
