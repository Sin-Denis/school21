/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:27:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 15:43:59 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void		key_add(t_Hash_table *t, char *key)
{
	int		i;
	size_t	hash_val;

	i = -1;
	while (++i < t->size)
	{
		hash_val = hash(key, t->size, i);
		if (Vert_vector_at(t->data, hash_val)->status != EXIST)
		{
			Vert_vector_store(t->data, hash_val, key);
			return ;
		}
	}
}
