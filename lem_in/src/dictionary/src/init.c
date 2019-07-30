/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:30:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 12:31:34 by jblue-da         ###   ########.fr       */
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

void			dict_destroy(t_dict **dict)
{
	int			i;

	i = -1;
    fields_destroy(&(*dict)->data, (*dict)->capacity);
	free(*dict);
	*dict = NULL;
}
