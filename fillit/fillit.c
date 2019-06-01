/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:05:15 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:06 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_map(t_map field)
{
	int		i;
	int		j;

	i = 0;
	while (i < field.size)
	{
		j = 0;
		while (j < field.size)
		{
			if (field.arr[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(field.arr[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	ft_free_map(&field);
}

int			ft_rec_new(t_dlist **fig_list, t_map *field)
{
	int		ret;
	t_fig	*fig;

	if ((*fig_list) == NULL)
		return (1);
	fig = (*fig_list)->content;
	ret = ft_process_fig(fig_list, field);
	if (ret == 1)
		ft_rec_new(fig_list, field);
	else if (ret == -1)
		ft_step_back(fig_list, field);
	return (-1);
}

t_map		fillit(t_dlist *fig_list)
{
	t_map	field;

	field.size = ft_get_size(fig_list);
	field.arr = NULL;
	ft_arrnew(&field);
	ft_arrclear(&field);
	while (ft_rec_new(&fig_list, &field) != 1)
		;
	return (field);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_dlist *list;

	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (ft_read_tet(fd, &list) == -1 || ft_dlstlen(list) > 26)
		{
			ft_putstr("error\n");
			close(fd);
			exit(-1);
		}
		ft_print_map(fillit(list));
	}
	else
	{
		ft_putstr("usage: ./fillit file_name\n");
		exit(-1);
	}
	close(fd);
	ft_dlstfree(&list);
	return (0);
}
