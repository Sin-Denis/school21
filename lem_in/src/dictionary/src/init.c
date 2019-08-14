/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:30:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/07 12:55:25 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"

t_dict		*dict_create(void)
{
	t_dict	*dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	dict->data = (t_field *)malloc(sizeof(t_field) * DICT_INIT_SIZE);
	dict->capacity = DICT_INIT_SIZE;
	dict->size = 0;
	fields_init(dict->data, dict->capacity);
	return (dict);
}

t_dict		*dict_create_size(int cap)
{
	t_dict	*dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	dict->data = (t_field *)malloc(sizeof(t_field) * cap);
	dict->capacity = cap;
	dict->size = 0;
	fields_init(dict->data, dict->capacity);
	return (dict);
}

void			dict_destroy(t_dict **dict)
{
	int			i;

	i = -1;
    fields_destroy(&(*dict)->data, (*dict)->capacity);
	free(*dict);
	*dict = NULL;
}
