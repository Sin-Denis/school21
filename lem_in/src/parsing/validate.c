/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:19:02 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/07 17:05:35 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

int check_each_char(char *line)
{
	while (*line)
	{
		if (!ft_isalnum(*line))
			return (-1);
		line++;
	}
	return (0);
}

int count_chars(char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{	
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int check_room_name(char *name)
{
	if (check_each_char(name) == -1 || *name == 'L')
			return (-1);
	return (0);
}

int check_coors(char *first_coor, char *second_coor)
{
	int i;

	i = 0;
	if (!ft_isnum(first_coor) || !ft_isnum(second_coor))
		return (-1);
	return (0);
}

int check_line(char *line)
{
	char **str;

	if (ft_strequ(line, "##start"))
		return (1);
	else if (ft_strequ(line, "##end"))
		return (2);
	else if (line[0] == '#')
		return (7);
	else if (ft_strchr(line, '-'))
	{
		str = ft_strsplit(line, '-');
		if (get_size_lem(str) != 2 || check_each_char(str[0]) == -1 || check_each_char(str[1]) == -1 || count_chars(line, '-') != 1)
		{
			free_string_array(&str);
			return (-1);
		}
		free_string_array(&str);		
		return (3);
	}
	str = ft_strsplit(line, ' ');
	if (get_size_lem(str) != 3 || check_room_name(str[0]) == -1 || check_coors(str[1], str[2]) == -1)
	{
		free_string_array(&str);
		return (-1);
	}
	free_string_array(&str);
	return (0);
}