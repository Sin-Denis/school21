/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:12:33 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:07 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_cube(char *str)
{
	int		col;
	int		row;
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		row = 0;
		while (++row < 5)
		{
			col = 1;
			while (str[i] != '\n' && str[i] != '\0')
			{
				col++;
				i++;
			}
			if (col != 5)
				return (-1);
			i++;
		}
		i++;
		if (row != 5)
			return (-1);
	}
	return (0);
}

int			ft_check_symbol(char *str)
{
	size_t i;

	i = 0;
	while ((str[i] == '.' || str[i] == '#' ||
	str[i] == '\n') && i < ft_strlen(str))
	{
		i++;
	}
	if (str[i] == '\0')
		return (0);
	return (-1);
}

char		ft_check_neighb(char *str, int i)
{
	int		k;

	k = 0;
	if (str[i - 1] == '#')
		k++;
	if (str[i - 5] == '#')
		k++;
	if (str[i + 1] == '#')
		k++;
	if (str[i + 5] == '#')
		k++;
	return (k);
}

int			ft_check_tet(char *str)
{
	size_t	i;
	int		k;
	int		sharp;
	int		neighb;

	i = 0;
	while (i < ft_strlen(str))
	{
		k = 0;
		sharp = 0;
		neighb = 0;
		while (k++ < 21)
		{
			if (str[i] == '#')
			{
				sharp++;
				neighb += ft_check_neighb(str, i);
			}
			i++;
		}
		if (neighb < 6 || sharp != 4)
			return (-1);
	}
	return (0);
}

int			ft_main_check(char *str)
{
	if (ft_check_cube(str) == 0 &&
		ft_check_tet(str) == 0 && ft_check_symbol(str) == 0)
		return (0);
	else
		return (-1);
}
