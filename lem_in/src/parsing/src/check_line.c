/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:08:00 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/16 18:27:47 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

int	check_line(char *line, t_graph *graph, int links)
{
	char **str;

	if (ft_strequ(line, "##start") && graph->num_ants != -1 && !links)
		return (1);
	else if (ft_strequ(line, "##end") && graph->num_ants != -1 && !links)
		return (2);
	else if (line && line[0] == '#' && !ft_strequ(line, "##start")
	&& !ft_strequ(line, "##end"))
		return (7);
	else if (check_link(line, graph))
		return (3);
	else if (graph->num_ants == -1 &&
	(graph->num_ants = get_ants_count(line)) > 0)
		return (4);
	str = ft_strsplit(line, ' ');
	if (get_size_lem(str) != 3 || check_room_name(str[0]) == -1
	|| check_coors(str[1], str[2]) == -1)
	{
		free_string_array(&str);
		return (-1);
	}
	free_string_array(&str);
	if (graph->num_ants != -1 && !links)
		return (0);
	return (-1);
}
