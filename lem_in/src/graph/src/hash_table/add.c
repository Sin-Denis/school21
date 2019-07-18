/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:27:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/18 09:47:13 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void			probing(t_Vert_vector *v, char *key, size_t m)
{
	size_t			j;
	size_t			hash_val;

	j = 0;
	while (j < m)
	{
		hash_val = hash(key, m, j);
		if (Vert_vector_at(v, hash_val)->status != EXIST)
		{
			Vert_vector_store(v, hash_val, key);
			return ;
		}
		++j;
	}
}

static void			rehash(t_Vert_vector *dst, t_Vert_vector *src, size_t m)
{
	size_t			i;
	t_Vertex		*v;

	i = 0;
	while (i < Vert_vector_size(src))
	{
		v = Vert_vector_at(src, i);
		if (v->status == EXIST)
			probing(dst, v->id, m);
		++i;
	}
}

static void			grow(t_Hash_table *t)
{
	t_Vert_vector	*new_vector;

	t->capacity *= 2;
	Vert_vector_create_size(&new_vector, t->capacity);
	rehash(new_vector, t->data, t->capacity);
	Vert_vector_destroy(&t->data);
	t->data = new_vector;
}

void		Hash_table_key_add(t_Hash_table *t, char *key)
{
	if (t->size * 3 >= 2 * t->capacity)
		grow(t);
	probing(t->data, key, t->capacity);
	++t->size;
}
