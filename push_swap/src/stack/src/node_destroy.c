#include "../inc/stack.h"

void			node_destroy(t_node **node)
{
	(*node)->next = NULL;
	(*node)->prev = NULL;
	free(*node);
	*node = NULL;
}
