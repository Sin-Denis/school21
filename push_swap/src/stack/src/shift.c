#include "../inc/stack.h"

void			stack_shift(t_stack *dst, t_stack *src)
{
	t_node *node;
	
	node = src->barrier->prev;
	src->barrier->prev = node->prev;
	node->prev->next = src->barrier;
	node->prev = dst->barrier->prev;
	node->next = dst->barrier;
	dst->barrier->prev->next = node;
	dst->barrier->prev = node;
	dst->size++;
	src->size--;
}
