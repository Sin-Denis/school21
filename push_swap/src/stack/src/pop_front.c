#include "../inc/stack.h"

void			stack_pop_front(t_stack *s)
{
	t_node		*delete_node;

	delete_node = s->barrier->next;
	s->barrier->next = delete_node->next;
	delete_node->next->prev = s->barrier;
	node_destroy(&delete_node);
	s->size--;
}
