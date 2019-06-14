#include "../inc/stack.h"

void			stack_swap(t_stack *s)
{
	t_node		*top;
	t_node		*prev_top;

	if (s->size <= 1)
		return ;
	top = s->barrier->prev;
	prev_top = top->prev;
	prev_top->next = top->next;
	prev_top->prev->next = top;
	top->prev = prev_top->prev;
	top->next = prev_top;
	prev_top->prev = top;
	s->barrier->prev = prev_top;
}
