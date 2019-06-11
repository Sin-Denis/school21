#include "vector.h"

static void		swap(vector_type *a, vector_type *b)
{
	vector_type tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int		partition(t_vector *v, int l, int r)
{
	int 		i;
	int 		j;
	int 		p;

	i = l;
	j = r;
	p = vector_get_elem(v, (l + r) / 2);
	while (i <= j)
	{
		while (vector_get_elem(v, i) < p)
			++i;
		while (vector_get_elem(v, j) > p)
			--j;
		if (i >= j)
			break ;
		swap(&v->data[i++], &v->data[j--]);
	}
	return (j);
}

static void		quick_sort_reqursion(t_vector *v, int l, int r)
{
	int			q;

	if (l < r)
	{
		q = partition(v, l, r);
		quick_sort_reqursion(v, l, q);
		quick_sort_reqursion(v, q + 1, r);
	}
}

void			vector_quick_sort(t_vector *v)
{
	quick_sort_reqursion(v, 0, vector_length(v) - 1);
}
