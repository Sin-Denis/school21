/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:20:59 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/17 13:21:43 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

int	check_states(t_graph *graph)
{
	if (STATE == -1 || !LINKS_COUNT || MANDATORY_COMMANDS != 2 ||
		graph->nodes->size == 0 ||
		graph->nodes->data[graph->start_idx].adj->size == 0
		|| graph->nodes->data[graph->end_idx].adj->size == 0)
		return (-1);
	return (0);
}

int	parse_main(t_graph *graph, t_string *output)
{
	t_dict		*rooms;
	t_p_dict	*coors;
	char		*line;

	*output = str_create_size(1);
	rooms = dict_create();
	coors = p_dict_create();
	line = NULL;
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
	return (check_states(graph) == -1 ? -1 : 0);
}
