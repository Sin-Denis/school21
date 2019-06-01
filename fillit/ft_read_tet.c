/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:57:19 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:19 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_width(t_fig *fig)
{
	int		min_x;
	int		max_x;
	int		i;

	i = 0;
	min_x = 5;
	max_x = -1;
	while (i < 4)
	{
		if (fig->figure[i].x < min_x)
			min_x = fig->figure[i].x;
		if (fig->figure[i].x > max_x)
			max_x = fig->figure[i].x;
		++i;
	}
	return (max_x - min_x + 1);
}

int			ft_high(t_fig *fig)
{
	int		min_y;
	int		max_y;
	int		i;

	i = 0;
	min_y = 5;
	max_y = -1;
	while (i < 4)
	{
		if (fig->figure[i].y < min_y)
			min_y = fig->figure[i].y;
		if (fig->figure[i].y > max_y)
			max_y = fig->figure[i].y;
		++i;
	}
	return (max_y - min_y + 1);
}

int			ft_read_tet(int file, t_dlist **fig_list)
{
	int		ret;
	char	buff[22];
	t_fig	fig;
	char	c;

	c = 'A';
	while ((ret = read(file, buff, 21)))
	{
		buff[ret] = '\0';
		if (ft_main_check(buff) == 0)
		{
			fig = *ft_find_fig(buff, &fig);
			fig.letter = c++;
			fig.with = ft_width(&fig);
			fig.high = ft_high(&fig);
			ft_dpushback(fig_list, ft_dlstnew((void*)&fig, sizeof(fig)));
		}
		else
			return (-1);
	}
	if (buff[20] != '\0')
		return (-1);
	return (1);
}

t_fig		*ft_find_fig(char *str, t_fig *fig)
{
	int		col;
	int		row;
	int		hash;

	row = -1;
	hash = 0;
	while (row++ < 4)
	{
		col = 0;
		while (*str != '\n' && ft_strlen(str))
		{
			if (*str == '#')
			{
				fig->figure[hash].x = col;
				fig->figure[hash].y = row;
				hash++;
			}
			str++;
			col++;
		}
		str++;
	}
	return (fig);
}
