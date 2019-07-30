/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:09:27 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 12:59:50 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"

void		dict_delete(t_dict *dict, const char *key)
{
	int		i;
	size_t	hash_val;

	i = -1;
	while ((size_t)++i < dict->capacity)
	{
		hash_val = hash(key, dict->capacity, i);
		if (dict->data[hash_val].status == BLANK)
			return ;
		if (dict->data[hash_val].status == DELETE)
			continue ;
		if (ft_strcmp(dict->data[hash_val].key, key) == 0)
		{
			dict->data[hash_val].status = DELETE;
			ft_strdel(&dict->data[hash_val].key);
		}
	}
}
