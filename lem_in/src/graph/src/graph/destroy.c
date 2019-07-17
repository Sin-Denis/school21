#include "../../include/graph.h"

void	Graph_destroy(t_Graph **g)
{
	Hash_table_destroy(&(*g)->table);
	ft_strdel(&(*g)->start_id);
	ft_strdel(&(*g)->end_id);
	free((*g));
	*g = NULL;
}