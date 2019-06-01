/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:51:14 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:30 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prepare_item(t_fs *form_string)
{
	prepare_item_flags(form_string);
	prepare_item_precision(form_string);
	prepare_item_size(form_string);
}

void	prepare(t_fs_vector *form_strings)
{
	int i;

	i = 0;
	while (i < fs_vector_length(form_strings))
		prepare_item(&form_strings->data[i++]);
}
