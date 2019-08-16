/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:22:18 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/15 20:52:24 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

void error_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

void init_flags_lem(int flags[])
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
}

int get_size_lem(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int get_ants_count(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return -1;
		i++;
	}
	i = ft_atoi(line);
	return (i);
}

void free_string_array(char ***str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return ;
	while ((*str)[i])
	{
		free((*str)[i]);
		(*str)[i++] = NULL;
	}
	free(*str);
}
