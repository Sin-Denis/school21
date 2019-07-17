/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:05:15 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/17 11:15:11 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

int			Hash_table_key_has(t_Hash_table *t, char *key)
{
	int		i;
	size_t	hash_val;

	i = -1;
	while (++i < t->capacity)
	{
		hash_val = hash(key, t->capacity, i);
		if (Vert_vector_at(t->data, hash_val)->status == BLANK)
			return (0);
		if (Vert_vector_at(t->data, hash_val)->status == DELETE)
			continue ;
		if (ft_strcmp(Vert_vector_at(t->data, hash_val)->id, key) == 0)
			return (1);
	}
	return (0);
}
