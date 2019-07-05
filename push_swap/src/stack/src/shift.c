#include "../inc/stack.h"

int			stack_shift(t_stack *dst, t_stack *src)
{
	t_node *node;

	if (src->size == 0)
		return (-1);
	node = src->barrier->prev;
	src->barrier->prev = node->prev;
	node->prev->next = src->barrier;
	if (dst->size == 0)
	{
		node->prev = dst->barrier;
		dst->barrier->prev = node;
		dst->barrier->next = node;
		node->next = dst->barrier;
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
	return (0);
}
