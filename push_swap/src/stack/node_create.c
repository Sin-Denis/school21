#include "stack.h"

t_node			*node_create(int value)
{
	t_node		*node;

	if ((node = (t_node *)malloc(sizeof(t_node))) == NULL)
		exit(1);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->order_idx = -1;
	node->operations_amount = 0;
	return (node);
}
