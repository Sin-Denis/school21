#include "../inc/stack.h"

void			stack_shift(t_stack *dst, t_stack *src)
{
	t_node *node;

	if (src->size == 0)
		return ;
	node = src->barrier->prev;
	src->barrier->prev = node->prev;
	node->prev->next = src->barrier;
	if (dst->size == 0)
	{
		node->prev = dst->barrier;
		dst->barrier->prev = node;
		dst->barrier->next = node;
		node->prev = dst->barrier;
	}
	else
	{
		node->prev = dst->barrier->prev;
		node->next = dst->barrier;
		dst->barrier->prev->next = node;
		dst->barrier->prev = node;
	}
	dst->size++;
	src->size--;
}
