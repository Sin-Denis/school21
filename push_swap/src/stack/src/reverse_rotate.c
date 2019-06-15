#include "../inc/stack.h"

void			stack_reverse_rotate(t_stack *s)
{
	t_node		*node;

	if (s->size <= 1)
		return ;
	node = s->barrier->next;
	node->next->prev = s->barrier;
	s->barrier->next = node->next;
	s->barrier->prev->next = node;
	node->prev = s->barrier->prev;
	node->next = s->barrier;
	s->barrier->prev = node;
}
