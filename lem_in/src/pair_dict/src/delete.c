/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:09:27 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 20:00:20 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

void		p_dict_delete(t_p_dict *dict, const t_pair *key)
{
	int		i;
	size_t	hash_val;

	i = -1;
	while ((size_t)++i < dict->capacity)
	{
		hash_val = p_hash(key, dict->capacity, i);
		if (dict->data[hash_val].status == BLANK)
			return ;
		if (dict->data[hash_val].status == DELETE)
			continue ;
		if (dict->data[hash_val].key->first == key->first && dict->data[hash_val].key->second == key->second)
		{
			dict->data[hash_val].status = DELETE;
			free(&dict->data[hash_val].key);
		}
	}
}
