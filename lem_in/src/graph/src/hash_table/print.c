#include "../../include/graph.h"

void	Hash_table_print(t_Hash_table *t)
{
	int i;
	t_Vertex *v;

	i = -1;
	while (++i < t->capacity)
	{
		v = Vert_vector_at(t->data, i);
		if (v->status == EXIST)
		{
			ft_printf("id: %10s status: %d power: %5d adj: ", v->id, v->status, v->pow);
			vector_print(v->adj);
			ft_printf("\n");
		}
	}
}
