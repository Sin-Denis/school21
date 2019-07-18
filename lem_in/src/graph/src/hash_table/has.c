/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:05:15 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/18 09:49:32 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

int			Hash_table_key_has(t_Hash_table *t, char *key)
{
	size_t	i;
	size_t	hash_val;

	i = 0;
	while (i < t->capacity)
	{
		hash_val = hash(key, t->capacity, i);
		if (Vert_vector_at(t->data, hash_val)->status == BLANK)
			return (0);
		if (Vert_vector_at(t->data, hash_val)->status == DELETE)
			continue ;
		if (ft_strcmp(Vert_vector_at(t->data, hash_val)->id, key) == 0)
			return (1);
		++i;
	}
	return (0);
}
