/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_fig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:12:26 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:10 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putfig(t_fig *fig, t_map *field)
{
	int i;
	int j;
	int min_x;
	int min_y;

	min_x = ft_dep_x(fig, field);
	min_y = ft_dep_y(fig, field);
	i = 0;
	j = 0;
	while (i < 4)
	{
		fig->figure[i].x -= min_x;
		fig->figure[i].y -= min_y;
		++i;
	}
	ft_letter(fig, field);
}

int		ft_movefig(t_fig *fig, t_map *field)
{
	int i;
	int arr[3];

	arr[0] = ft_max_x(fig);
	arr[1] = ft_max_y(fig);
	arr[2] = ft_dep_x(fig, field);
	i = -1;
	while (++i < 4)
		if (arr[0] < field->size - 1)
		{
			field->arr[fig->figure[i].y][fig->figure[i].x] -= fig->letter;
			fig->figure[i].x += 1;
		}
		else if (arr[1] < field->size - 1)
		{
			field->arr[fig->figure[i].y][fig->figure[i].x] -= fig->letter;
			fig->figure[i].y += 1;
			fig->figure[i].x -= arr[2];
		}
		else
			return (-1);
	ft_letter(fig, field);
	return (0);
}

void	ft_step_back(t_dlist **fig_list, t_map *field)
{
	ft_clear_fig((*fig_list)->content, field);
	while ((*fig_list)->prev != NULL)
	{
		if (ft_movefig((*fig_list)->prev->content, field) == -1)
		{
			ft_clear_fig((*fig_list)->prev->content, field);
			*fig_list = (*fig_list)->prev;
		}
		else
			return ;
	}
	ft_plus_field(field);
	return ;
}

int		ft_process_fig(t_dlist **fig_list, t_map *field)
{
	if (ft_putcheck((*fig_list)->content, field) == 1)
	{
		ft_putfig((*fig_list)->content, field);
		while (ft_intersection(field) && !ft_end((*fig_list)->content, field))
			ft_movefig((*fig_list)->content, field);
		if (ft_intersection(field))
			return (-1);
		(*fig_list) = (*fig_list)->next;
		return (1);
	}
	while ((*fig_list)->prev != NULL)
		*fig_list = (*fig_list)->prev;
	ft_plus_field(field);
	return (0);
}
