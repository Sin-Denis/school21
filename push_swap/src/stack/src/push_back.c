#include "../inc/stack.h"

void			stack_push_back(t_stack *s, int elem)
{
	t_node		*new_node;

	new_node = node_create(elem);
	new_node->next = s->barrier;
	if (s->size == 0)
	{
		s->barrier->prev = new_node;
		s->barrier->next = new_node;
		new_node->prev = s->barrier;
	}
	else
	{
		s->barrier->prev->next = new_node;
		new_node->prev = s->barrier->prev;
		s->barrier->prev = new_node;
	}
	s->size++;
}
