/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:20:59 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/15 21:51:40 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#define STATE flags[0]
#define LINKS_COUNT flags[1]
#define MANDATORY_COMMANDS flags[2]
#define IDX flags[3]

int		flags[4];

static void parse_rooms_into_graph(t_graph *graph, char *line)
{
	char **str;

	str = ft_strsplit(line, ' ');
	if (str[1] == NULL || **str == '#' || **str == 'L')
	{
		free_string_array(&str);
		return ;
	}
	if (toggle == 1)
	{
		graph_add_start_vert(graph, str[0], ft_atoi(str[1]), ft_atoi(str[2]));
		MANDATORY_COMMANDS++;
		toggle = 0;
	}
	else if (toggle == 2)
	{
		graph_add_end_vert(graph, str[0], ft_atoi(str[1]), ft_atoi(str[2]));
		MANDATORY_COMMANDS++;		
		toggle = 0;
	}
	else
		graph_add_vert(graph, str[0], ft_atoi(str[1]), ft_atoi(str[2]));
	free_string_array(&str);
}

static int parse_links(t_graph *graph, t_dict *rooms,
char *line, int *links_count)
{
	char **str;
	int idx0;
	int idx1;

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
		return -1;
	}
	graph_add_edge(graph, idx0, idx1);
	free_string_array(&str);
	(*links_count)++;
	return (0);
}

static int parse_into_dict(t_dict *rooms, t_p_dict *coors, char *line, int idx)
{
	char **str;
	t_pair *pair;

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

static int read_line(char **line, t_graph *graph, t_string *output)
{
	int flag;

	if (get_next_line(0, line) == 0)
		return (5);
	flag = check_line(*line, graph, LINKS_COUNT);
	if (flag == -1)
		return (-1);
	else if (flag == 7)
	{
		if ((*line)[1] != '#')
		{
			str_pushstr(output, *line);
			str_pushchar(output, '\n');
		}
		return (7);
	}
	else if (flag == 1 || flag == 2)
	{
		toggle = flag;
		if ((flag == 2 && graph->end_idx != -1) ||
		(graph->start_idx != -1 && flag == 1))
			return (-1);
		graph->end_idx = graph->end_idx;
	}
	str_pushstr(output, *line);
	str_pushchar(output, '\n');
	return(flag);
}

void parse_line(t_dict *rooms, t_p_dict *coors, t_graph *graph, char *line)
{
	parse_into_dict(rooms, coors, line, IDX) == -1 ? error_exit("ERROR") : 0;
	parse_rooms_into_graph(graph, line);
	parse_links(graph, rooms, line, &LINKS_COUNT) == -1 ?
	error_exit("ERROR") : 0;
}

int check_states(t_graph *graph)
{
	if (STATE == -1 || !LINKS_COUNT || MANDATORY_COMMANDS != 2 ||
		graph->nodes->size == 0 ||
		graph->nodes->data[graph->start_idx].adj->size == 0
		|| graph->nodes->data[graph->end_idx].adj->size == 0)
		return (-1);
	return 0;
}

int parse_main(t_graph *graph, t_string *output)
{
	t_dict	*rooms;
	t_p_dict *coors;
	char	*line;

	*output = str_create_size(1);
	rooms = dict_create();
	coors = p_dict_create();
	while ((STATE = read_line(&line, graph, output)) != -1)
	{
		if (STATE == 5)
		{
			ft_strdel(&line);
			break ;
		}
		parse_line(rooms, coors, graph, line);
		IDX = STATE == 0 ? IDX + 1 : IDX;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	dict_destroy(&rooms);
	p_dict_destroy(&coors);
	return(check_states(graph) == -1 ? -1 : 0);
}
