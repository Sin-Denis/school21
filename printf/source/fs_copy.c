/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:46:29 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:29 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fs_copy(t_fs *new_form_string, t_fs *form_string)
{
	new_form_string->flags = ft_strdup(form_string->flags);
	new_form_string->width = form_string->width;
	new_form_string->precision = form_string->precision;
	new_form_string->size = ft_strdup(form_string->size);
	new_form_string->type = form_string->type;
}
