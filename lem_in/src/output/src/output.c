/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:01:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 13:25:49 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/output.h"

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
		vector_set_elem(offsets, i, vector_get_elem(distribution, i - 1)
		+ vector_get_elem(offsets, i - 1));
	}
	return (offsets);
}

static t_pair	*get_distr_offset(int a, long long b)
{
	t_pair *p;
	
	p = (t_pair *)malloc(sizeof(t_pair));
	p->first = a;
	p->second = b;
	return p;
}

static void	output_body(t_graph *g, t_vector **roads, t_vector *distribution, int num_roads)
{
	int				i;
	int				j;
	int				num_lines;
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
			road_handler(g, roads[j], vector_pair_at(indexes, j),
			get_distr_offset(distribution->data[j], vector_get_elem(offsets, j)));
		ft_printf("\n");
	}
	vector_destroy(&offsets);
	vector_pair_destroy(&indexes);
}

void			output(t_graph *g, t_string *str)
{
	int			i;
	int 		num_roads;
	t_vector	**roads;
	t_vector	*distribution;
	
	num_roads = get_num_roads(g);
	roads = get_all_roads(g, num_roads);
	distribution = get_distribution(roads, g->num_ants, num_roads);
	str_print(str);
	output_body(g, roads, distribution, num_roads);
	i = 0;
	while (i < num_roads)
		vector_destroy(&roads[i++]);
	free(roads);
	vector_destroy(&distribution);
}
