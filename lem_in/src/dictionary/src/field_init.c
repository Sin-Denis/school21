/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:55:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/07 13:32:26 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"

void			field_init(t_field *field, const char *key, int val)
{
	field->key = ft_strdup(key);
	field->val = val;
	field->status = EXIST;
}

void fields_init(t_field *fields, size_t size)
{
	int		i;

	i = -1;
	while ((size_t)++i < size)
	{
		fields[i].status = BLANK;
		fields[i].key = NULL;
		fields[i].val = -1;
	}
}

void			fields_destroy(t_field **data, size_t size)
{
	int i;

	i = -1;
	while ((size_t)++i < size)
		if ((*data)[i].status == EXIST)
			ft_strdel(&(*data)[i].key);
	free(*data);
	*data = NULL;
}
