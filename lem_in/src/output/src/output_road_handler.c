/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_road_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:43:21 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/18 16:13:00 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/output.h"

static void		road_handler1(t_graph *g,
t_vector *road, t_pair *indexes, t_pair *distr_offset)
{
	int			i;
	int			j;

	i = indexes->first;
	j = indexes->second;
	while (i < distr_offset->first)
	{
		if (!(distr_offset->second == 0 && i == indexes->first))
			ft_printf(" ");
		ft_printf("L%d-%s", distr_offset->second + i + 1,
		vert_vector_at(g->nodes, road->data[j - i])->name);
		++i;
	}
}

static void		road_handler2(t_graph *g,
t_vector *road, t_pair *indexes, t_pair *distr_offset)
{
	int			i;
	int			j;

	i = 0;
	j = indexes->second;
	while (i <= j)
	{
		if (!(distr_offset->second == 0 && i == 0))
			ft_printf(" ");
		ft_printf("L%d-%s", distr_offset->second + i + 1,
		vert_vector_at(g->nodes, road->data[j - i])->name);
		++i;
	}
}

static void		road_handler3(t_graph *g,
t_vector *road, t_pair *indexes, t_pair *distr_offset)
{
	int			i;
	int			j;

	i = indexes->first;
	j = indexes->second;
	while (i <= j)
	{
		if (!(distr_offset->second == 0 && i == indexes->first))
			ft_printf(" ");
		ft_printf("L%d-%s", distr_offset->second + i + 1,
		vert_vector_at(g->nodes, road->data[j - i])->name);
		++i;
	}
}

void			road_handler(t_graph *g,
t_vector *road, t_pair *indexes, t_pair *distr_offset)
{
	if (distr_offset->first == 0)
	{
		free(distr_offset);
		return ;
	}
	if (indexes->second >= distr_offset->first)
		road_handler1(g, road, indexes, distr_offset);
	else if (indexes->second < road->size - 1)
		road_handler2(g, road, indexes, distr_offset);
	else
		road_handler3(g, road, indexes, distr_offset);
	if (indexes->second >= road->size - 1)
		++indexes->first;
	++indexes->second;
	free(distr_offset);
}
