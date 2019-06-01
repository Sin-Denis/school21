/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_coords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:38:02 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:09 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_letter(t_fig *fig, t_map *field)
{
	int i;

	i = 0;
	while (i < 4)
	{
		field->arr[fig->figure[i].y][fig->figure[i].x] += fig->letter;
		++i;
	}
}

int		ft_max_x(t_fig *fig)
{
	int i;
	int max_x;

	i = 0;
	max_x = 0;
	while (i < 4)
	{
		if (fig->figure[i].x > max_x)
			max_x = fig->figure[i].x;
		++i;
	}
	return (max_x);
}

int		ft_max_y(t_fig *fig)
{
	int i;
	int max_y;

	i = 0;
	max_y = 0;
	while (i < 4)
	{
		if (fig->figure[i].y > max_y)
			max_y = fig->figure[i].y;
		++i;
	}
	return (max_y);
}

int		ft_dep_x(t_fig *fig, t_map *field)
{
	int i;
	int min_x;

	i = 0;
	min_x = field->size;
	while (i < 4)
	{
		if (fig->figure[i].x < min_x)
			min_x = fig->figure[i].x;
		++i;
	}
	return (min_x);
}

int		ft_dep_y(t_fig *fig, t_map *field)
{
	int i;
	int min_y;

	i = 0;
	min_y = field->size;
	while (i < 4)
	{
		if (fig->figure[i].y < min_y)
			min_y = fig->figure[i].y;
		++i;
	}
	return (min_y);
}
