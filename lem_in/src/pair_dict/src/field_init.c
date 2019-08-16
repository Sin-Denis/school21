/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:55:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 20:00:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

void			p_field_init(t_p_field *field, const t_pair *key)
{
	field->key == NULL ? field->key = (t_pair*)malloc(sizeof(t_pair)) : 0;
	field->key->first = key->first;
	field->key->second = key->second;
	field->status = EXIST;
}

void p_fields_init(t_p_field *fields, size_t size)
{
	int		i;

	i = -1;
	while ((size_t)++i < size)
	{
		fields[i].status = BLANK;
		fields[i].key = NULL;
	}
}

void			p_fields_destroy(t_p_field **data, size_t size)
{
	int i;

	i = -1;
	while ((size_t)++i < size)
		if ((*data)[i].status == EXIST)
			free((*data)[i].key);
	free(*data);
	*data = NULL;
}
