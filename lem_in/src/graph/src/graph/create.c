#include "../../include/graph.h"

void	Graph_create(t_Graph **g)
{
	(*g) = (t_Graph *)malloc(sizeof(t_Graph));
	Hash_table_create(&(*g)->table);
	(*g)->start_id = NULL;
	(*g)->end_id = NULL;
	(*g)->size = 0;
}
