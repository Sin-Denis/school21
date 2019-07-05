#include "../../inc/push_swap.h"

static void		transform_to_vector(t_vector *v, t_stack *s)
{
	int			i;
	t_node		*iter;

	i = -1;
	iter = s->barrier->next;
	while (++i < s->size)
	{
		vector_push_back(v, iter->value);
		iter = iter->next;
	}
}

static int		bin_search(t_vector *v, int key)
{
	int			l;
	int			m;
	int			r;

	l = -1;
	r = vector_length(v);
	while (l + 1 < r)
	{
		m = (l + r) / 2;
		if (vector_get_elem(v, m) < key)
			l = m;
		else
			r = m;
	}
	return (r); 
}

static void		set_order(t_stack *s, t_vector *v)
{
	int			i;
	int			val;
	t_node		*iter;

	i = -1;
	iter = s->barrier->next;
	while (++i < s->size)
	{
		iter->order_idx = bin_search(v, iter->value);
		iter = iter->next;
	}
}

void			order_calculate(t_stack *s)
{
    t_vector	*v;

	v = vector_create(0);
	transform_to_vector(v, s);
	vector_quick_sort(v);
	set_order(s, v);
	vector_destroy(&v);
}
