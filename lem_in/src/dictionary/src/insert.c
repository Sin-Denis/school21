/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:35:09 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/07 13:19:10 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"

static void			probing(t_field *data, size_t cap, const char *key, int val)
{
	int				i;
	size_t			hash_val;

	i = -1;
	while ((size_t)++i < cap)
	{
		hash_val = hash(key, cap, i);
		if (data[hash_val].status != EXIST)
		{
			field_init(&data[hash_val], key, val);
			return ;
		}
	}
}

static void	rehash(t_dict *dict, t_field *fields)
{
	int		i;

	i = -1;
	while ((size_t)++i < dict->capacity)
		if (dict->data[i].status == EXIST)
			probing(fields, dict->capacity * 2, dict->data[i].key, dict->data[i].val);
}

static void	grow(t_dict *dict)
{
	t_field	*new_data;

	new_data = (t_field *)malloc(sizeof(t_field) * dict->capacity * 2);
	rehash(dict, new_data);
	fields_destroy(&dict->data, dict->capacity);
	dict->data = new_data;
	dict->capacity *= 2;
}

void	dict_insert(t_dict *dict, const char *key, int val)
{
	if (dict->size * 3 >= 2 *dict->capacity)
		grow(dict);
	probing(dict->data, dict->capacity, key, val);
	++dict->size;
}
