#include "../inc/stack.h"

int				stack_rotate(t_stack *s)
{
	t_node		*node;

	if (s->size <= 1)
		return (-1);
	node = s->barrier->prev;
	node->prev->next = s->barrier;
	s->barrier->prev = node->prev;
	s->barrier->next->prev = node;
	node->next = s->barrier->next;
	node->prev = s->barrier;
	s->barrier->next = node;
	return (0);
}
