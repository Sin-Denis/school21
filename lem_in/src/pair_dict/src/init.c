/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:30:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:55:42 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

t_p_dict		*p_dict_create(void)
{
	t_p_dict	*dict;

	dict = (t_p_dict *)malloc(sizeof(t_p_dict));
	dict->data = (t_p_field *)malloc(sizeof(t_p_field) * DICT_INIT_SIZE);
	dict->capacity = DICT_INIT_SIZE;
	dict->size = 0;
	p_fields_init(dict->data, dict->capacity);
	return (dict);
}

t_p_dict		*p_dict_create_size(int cap)
{
	t_p_dict	*dict;

	dict = (t_p_dict *)malloc(sizeof(t_p_dict));
	dict->data = (t_p_field *)malloc(sizeof(t_p_field) * cap);
	dict->capacity = cap;
	dict->size = 0;
	p_fields_init(dict->data, dict->capacity);
	return (dict);
}

void			p_dict_destroy(t_p_dict **dict)
{
	int			i;

	i = -1;
	p_fields_destroy(&(*dict)->data, (*dict)->capacity);
	free(*dict);
	*dict = NULL;
}
