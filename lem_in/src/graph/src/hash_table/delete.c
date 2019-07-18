#include "../../include/graph.h"

void			Hash_table_key_delete(t_Hash_table *t, char *key)
{
	size_t		i;
	t_Vertex	*v;
	size_t		hash_val;

	i = 0;
	while (i < t->capacity)
	{
		hash_val = hash(key, t->capacity, i);
		v = Vert_vector_at(t->data, hash_val);
		if (v->status == BLANK)
			return ;
		if (v->status == DELETE)
			continue ;
		if (ft_strcmp(v->id, key) == 0)
		{
			v->status = DELETE;
			ft_strdel(&v->id);
			vector_destroy(&v->adj);
		}
		++i;
	}
}
