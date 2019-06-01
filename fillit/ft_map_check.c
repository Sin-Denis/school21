/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:40:55 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:09 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_putcheck(t_fig *fig, t_map *field)
{
	if (fig->with > field->size || fig->high > field->size)
		return (0);
	return (1);
}

int		ft_end(t_fig *fig, t_map *field)
{
	if (ft_max_x(fig) == field->size - 1 && ft_max_y(fig) == field->size - 1)
		return (1);
	return (0);
}

int		ft_intersection(t_map *field)
{
	int i;
	int j;

	i = 0;
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
		{
			if (field->arr[i][j] > 130)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int		ft_get_size(t_dlist *list)
{
	int i;
	int nb;

	nb = ft_dlstlen(list) * 4;
	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}
