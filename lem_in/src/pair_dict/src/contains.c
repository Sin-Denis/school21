/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:15:44 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:49:51 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

int			p_dict_contains(t_p_dict *dict, const t_pair *key)
{
	int		i;
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
		if (dict->data[hash_val].status == EXIST &&
		dict->data[hash_val].key->first == key->first &&
		dict->data[hash_val].key->second == key->second)
			return (1);
	}
	return (0);
}
