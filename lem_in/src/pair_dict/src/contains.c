/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:15:44 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 20:31:16 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

int		p_dict_contains(t_p_dict *dict, const t_pair *key)
{
	int	i;
	size_t	hash_val;

	i = -1;
	while ((size_t)++i < dict->capacity)
	{
		hash_val = p_hash(key, dict->capacity, i);
		if (dict->data[hash_val].status == BLANK)
			return (0);
		if (dict->data[hash_val].status == DELETE)
			continue ;
		if (dict->data[hash_val].key == NULL)
			continue ;
		if (dict->data[hash_val].status == EXIST && dict->data[hash_val].key->first == key->first && dict->data[hash_val].key->second == key->second)
			return (1);
	}
	return (0);
}
