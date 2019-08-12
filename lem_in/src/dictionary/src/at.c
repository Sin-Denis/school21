/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:15:44 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 18:35:59 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"

int		dict_at(t_dict *dict, const char *key)
{
	int	i;
	size_t	hash_val;

	i = -1;
	while ((size_t)++i < dict->capacity)
	{
		hash_val = hash(key, dict->capacity, i);
		if (dict->data[hash_val].status == BLANK)
			return (-2147483648);
		if (dict->data[hash_val].status == DELETE)
			continue ;
		if (dict->data[hash_val].key == NULL)
			continue ;
		if (dict->data[hash_val].status == EXIST && ft_strcmp(dict->data[hash_val].key, key) == 0)
			return (dict->data[hash_val].val);
	}
	return (-2147483648);
}
