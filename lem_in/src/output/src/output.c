/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:01:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/06 17:50:26 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/output.h"

static int get_offset(t_vector *distribution, int idx)
{
	if (idx == 0)
		return 0;
	return (vector_get_elem(distribution, idx - 1));
}

static void road_handler(t_graph *g, t_vector *road, t_pair *indexes, t_pair *distr_offset)
{
	int		i;
	int		j;

	if (distr_offset->first == 0)
		return ;
	
	if (indexes->second >= distr_offset->first)
	{
		// ft_printf("1\n");
		i = indexes->first;
		j = indexes->second;
		while (i < distr_offset->first)
		{
			ft_printf("L%d-%s ", distr_offset->second + i + 1, vert_vector_at(g->nodes, road->data[j - i])->name);
			++i;
		}
	}
	else if (indexes->second < road->size - 1)
	{
		// ft_printf("2\n");
		i = 0;
		j = indexes->second;
		while (i <= j)
		{
			ft_printf("L%d-%s ", distr_offset->second + i + 1, vert_vector_at(g->nodes, road->data[j - i])->name);
			++i;
		}
	}
	else
	{
		// ft_printf("3\n");
		i = indexes->first;
		j = indexes->second;
		while (i <= j)
		{
			ft_printf("L%d-%s ", distr_offset->second + i + 1, vert_vector_at(g->nodes, road->data[j - i])->name);
			++i;
		}
	}
	if (indexes->second >= road->size - 1)
		++indexes->first;
	++indexes->second;
}

void	output(t_graph *g, t_vector **roads, t_vector *distribution, int num_roads)
{
	int				i;
	int				j;
	int				num_lines;
	t_pair			p;
	t_vector_pair	*indexes;

	num_lines = vector_length(roads[0]) + vector_get_elem(distribution, 0) - 1;
	indexes = vector_pair_create(num_roads);
	i = -1;
	while (++i < num_lines)
	{
		j = -1;
		while (++j < num_roads)
		{
			p.first = distribution->data[j];
			p.second = get_offset(distribution, j);
			road_handler(
				g,
				roads[j],
				vector_pair_at(indexes, j),
				&p);
		}
		ft_printf("\n");
	}
}