/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:35:09 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 17:55:33 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

static void			p_probing(t_p_field *data, size_t cap, const t_pair *key)
{
	int				i;
	size_t			hash_val;

	i = -1;
	while ((size_t)++i < cap)
	{
		hash_val = p_hash(key, cap, i);
		if (data[hash_val].status != EXIST)
		{
			p_field_init(&data[hash_val], key);
			return ;
		}
	}
}

static void	p_rehash(t_p_dict *dict, t_p_field *fields)
{
	int		i;

	i = -1;
	while ((size_t)++i < dict->capacity)
		if (dict->data[i].status == EXIST)
			p_probing(fields, dict->capacity * 2, dict->data[i].key);
}

static void	p_grow(t_p_dict *dict)
{
	t_p_field	*new_data;

	new_data = (t_p_field *)malloc(sizeof(t_p_field) * dict->capacity * 2);
	p_fields_init(new_data, dict->capacity * 2);
	p_rehash(dict, new_data);
	p_fields_destroy(&dict->data, dict->capacity);
	dict->data = new_data;
	dict->capacity *= 2;
}

void	p_dict_insert(t_p_dict *dict, const t_pair *key)
{
	if (dict->size * 3 >= 2 *dict->capacity)
		p_grow(dict);
	p_probing(dict->data, dict->capacity, key);
	++dict->size;
}
