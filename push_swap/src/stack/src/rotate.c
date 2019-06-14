#include "../inc/stack.h"

void			stack_rotate(t_stack *s)
{
	t_node		*node;

	node = s->barrier->prev;
	node->prev->next = s->barrier;
	s->barrier->prev = node->prev;
	s->barrier->next->prev = node;
	node->next = s->barrier->next;
	node->prev = s->barrier;
	s->barrier->next = node;
}
