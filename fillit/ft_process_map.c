/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:36:07 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:10 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clear_fig(t_fig *fig, t_map *field)
{
	int i;

	i = 0;
	while (i < 4)
	{
		field->arr[fig->figure[i].y][fig->figure[i].x] -= fig->letter;
		i++;
	}
}

void	ft_arrnew(t_map *field)
{
	int i;

	i = 0;
	if (!(field->arr = (int **)malloc(sizeof(int *) * field->size)))
		return ;
	while (i < field->size)
	{
		if (!((field->arr)[i] = (int *)malloc(sizeof(int) * field->size)))
			return ;
		++i;
	}
}

void	ft_arrclear(t_map *field)
{
	int i;
	int j;

	i = 0;
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
		{
			field->arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_free_map(t_map *field)
{
	int i;

	i = 0;
	while (i < field->size)
	{
		free(field->arr[i]);
		++i;
	}
	free((field->arr));
}

void	ft_plus_field(t_map *field)
{
	ft_free_map(field);
	field->size++;
	ft_arrnew(field);
	ft_arrclear(field);
}
