/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:44:15 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 16:03:11 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

int		key_delete(t_Hash_table *t, char *key)
{
	int		i;
	size_t	hash_val;

	i = -1;
	while (++i < t->size)
	{
		hash_val = hash(key, t->size, i);
		if (Vert_vector_at(t->data, hash_val)->status == BLANK)
			return (0);
		if (Vert_vector_at(t->data, hash_val)->status == DELETE)
			continue ;
		if (ft_strcmp(Vert_vector_at(t->data, hash_val)->id, key) == 0)
			return (1);
	}
	return (0);
}
