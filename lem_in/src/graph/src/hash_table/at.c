#include "../../include/graph.h"

t_Vertex		*Hash_table_at(t_Hash_table *t, char *key)
{
	int			i;
	t_Vertex	*v;
	size_t		hash_val;

	i = -1;
	while (++i < t->capacity)
	{
		hash_val = hash(key, t->capacity, i);
		v = Vert_vector_at(t->data, hash_val);
		if (v->status == BLANK)
			return (NULL);
		if (v->status == DELETE)
			continue ;
		if (ft_strcmp(v->id, key) == 0)
			return (v);
	}
	return (NULL);
}

int				Hash_table_idx(t_Hash_table *t, char *key)
{
	int			i;
	t_Vertex	*v;
	size_t		hash_val;

	i = -1;
	while (++i < t->capacity)
	{
		hash_val = hash(key, t->capacity, i);
		v = Vert_vector_at(t->data, hash_val);
		if (v->status == BLANK)
			return (-1);
		if (v->status == DELETE)
			continue ;
		if (ft_strcmp(v->id, key) == 0)
			return (hash_val + i);
	}
	return (-1);
}
