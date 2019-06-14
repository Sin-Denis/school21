#include "../inc/stack.h"

void			stack_pop_back(t_stack *s)
{
	t_node		*delete_node;

	delete_node = s->barrier->prev;
	s->barrier->prev = delete_node->prev;
	delete_node->prev->next = delete_node;
	node_destroy(&delete_node);
	s->size--;
}
