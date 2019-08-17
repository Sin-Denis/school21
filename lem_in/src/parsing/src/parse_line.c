/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:53:23 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/17 14:16:39 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

void	parse_rooms_into_graph(t_graph *graph, char *line)
{
	char **str;

	str = ft_strsplit(line, ' ');
	if (str[1] == NULL || **str == '#' || **str == 'L')
	{
		free_string_array(&str);
		return ;
	}
	if (g_toggle == 1)
	{
		graph_add_start_vert(graph, str[0], ft_atoi(str[1]), ft_atoi(str[2]));
		MANDATORY_COMMANDS++;
		g_toggle = 0;
	}
	else if (g_toggle == 2)
	{
		graph_add_end_vert(graph, str[0], ft_atoi(str[1]), ft_atoi(str[2]));
		MANDATORY_COMMANDS++;
		g_toggle = 0;
	}
	else
		graph_add_vert(graph, str[0], ft_atoi(str[1]), ft_atoi(str[2]));
	free_string_array(&str);
}

int		parse_links(t_graph *graph, t_dict *rooms,
char *line, int *links_count)
{
	char	**str;
	int		idx0;
	int		idx1;

	str = ft_strsplit(line, '-');
	if (str[1] == NULL || **str == '#' || **str == 'L')
	{
		free_string_array(&str);
		return (0);
	}
	idx0 = dict_at(rooms, str[0]);
	idx1 = dict_at(rooms, str[1]);
	if (idx0 == -2147483648 || idx1 == -2147483648 || idx1 == idx0)
	{
		free_string_array(&str);
		return (-1);
	}
	if (vertex_get_weight(graph_get_vert(graph, idx0), idx1) == -1)
	{
		graph_add_edge(graph, idx0, idx1);
		(*links_count)++;
	}
	free_string_array(&str);
	return (0);
}

int		parse_into_dict(t_dict *rooms, t_p_dict *coors, char *line, int idx)
{
	char	**str;
	t_pair	*pair;

	str = ft_strsplit(line, ' ');
	if (str[1] == NULL || **str == '#' || **str == 'L')
	{
		free_string_array(&str);
		return (0);
	}
	pair = pair_create(ft_atoi(str[1]), ft_atoi(str[2]));
	if (dict_at(rooms, str[0]) != -2147483648 || p_dict_contains(coors, pair))
	{
		free_string_array(&str);
		free(pair);
		return (-1);
	}
	p_dict_insert(coors, pair);
	free(pair);
	dict_insert(rooms, str[0], idx);
	free_string_array(&str);
	return (0);
}

int		read_line(char **line, t_graph *graph, t_string *output)
{
	int flag;

	if (get_next_line(0, line) == 0)
		return (5);
	if ((flag = check_line(*line, graph, LINKS_COUNT)) == -1)
		return (-1);
	else if (flag == 7)
	{
		str_pushstr(output, *line);
		str_pushchar(output, '\n');
		return (7);
	}
	else if (flag == 1 || flag == 2)
	{
		g_toggle = flag;
		if ((flag == 2 && graph->end_idx != -1) ||
		(graph->start_idx != -1 && flag == 1))
			return (-1);
		graph->end_idx = graph->end_idx;
	}
	str_pushstr(output, *line);
	str_pushchar(output, '\n');
	return (flag);
}

void	parse_line(t_dict *rooms, t_p_dict *coors, t_graph *graph, char *line)
{
	parse_into_dict(rooms, coors, line, IDX) == -1 ?
	error_exit("ERROR", &graph) : 0;
	parse_rooms_into_graph(graph, line);
	parse_links(graph, rooms, line, &LINKS_COUNT) == -1 ?
	error_exit("ERROR", &graph) : 0;
}
