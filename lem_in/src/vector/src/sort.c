/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:45 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 09:57:51 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

static void		swap(t_vector_type *a, t_vector_type *b)
{
	t_vector_type tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int		partition(t_vector *v, int l, int r)
{
	int			i;
	int			j;
	int			p;

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
