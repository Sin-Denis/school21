#include "../../include/graph.h"

void			Graph_add_edge(t_Graph *g, char *name1, char *name2)
{
	t_Vertex	*v1;
	int			idx2;

	v1 = Hash_table_at(g->table, name1);
	idx2 = Hash_table_idx(g->table, name2);

	if (v1->adj == NULL)
		v1->adj =  vector_create(0);
	vector_push_back(v1->adj, idx2);
}
