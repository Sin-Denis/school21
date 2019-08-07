/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:01:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/07 10:41:59 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/output.h"

static void road_handler(t_graph *g, t_vector *road, t_pair *indexes, t_pair *distr_offset)
{
	int		i;
	int		j;

	if (distr_offset->first == 0)
		return ;
	if (indexes->second >= distr_offset->first)
	{
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

static t_vector *get_offsets(t_vector *distribution)
{
	t_vector	*offsets;
	int i;

	i = -1;
	offsets = vector_create(distribution->size);
	while (++i < distribution->size)
	{
		if (i == 0)
		{
			vector_set_elem(offsets, i, 0);
			continue ;
		}
		vector_set_elem(offsets, i, vector_get_elem(distribution, i - 1) + vector_get_elem(offsets, i - 1));
	}
	return (offsets);
}

void	output(t_graph *g, t_vector **roads, t_vector *distribution, int num_roads)
{
	int				i;
	int				j;
	int				num_lines;
	t_pair			p;
	t_vector		*offsets;
	t_vector_pair	*indexes;

	offsets = get_offsets(distribution);
	num_lines = vector_length(roads[0]) + vector_get_elem(distribution, 0) - 1;
	indexes = vector_pair_create(num_roads);
	i = -1;
	while (++i < num_lines)
	{
		j = -1;
		while (++j < num_roads)
		{
			p.first = distribution->data[j];
			p.second = vector_get_elem(offsets, j);
			road_handler(
				g,
				roads[j],
				vector_pair_at(indexes, j),
				&p);
		}
		ft_printf("\n");
	}
}
