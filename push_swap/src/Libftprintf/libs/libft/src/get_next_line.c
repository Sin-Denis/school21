/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:42:47 by jblue-da          #+#    #+#             */
/*   Updated: 2019/01/03 15:39:47 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				glue(char **s1, char *s2)
{
	char		*tmp;

	tmp = NULL;
	if (*s1 == NULL)
	{
		*s1 = ft_strdup(s2);
		if (s1 == NULL)
			return (-1);
	}
	else
	{
		tmp = ft_strdup(*s1);
		if (tmp == NULL)
			return (-1);
		free(*s1);
		*s1 = ft_strjoin(tmp, s2);
		if (*s1 == NULL)
			return (-1);
		free(tmp);
	}
	return (1);
}

int				get_line(char **buf, char **line, int len)
{
	char		*tmp;

	tmp = NULL;
	if (ft_strchr(*buf, '\n'))
	{
		while ((*buf)[len] != '\n')
			len++;
		if (!(*line = ft_strsub(*buf, 0, len)))
			return (-1);
		if ((int)ft_strlen(*buf) == len + 1)
			ft_strdel(buf);
		else
		{
			tmp = *buf;
			if (!(*buf = ft_strsub(*buf, len + 1, ft_strlen(*buf) - len)))
				return (-1);
			ft_strdel(&tmp);
		}
	}
	else if (!(*line = ft_strdup(*buf)))
		return (-1);
	else
		ft_strdel(buf);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*arr[65536];
	int			size;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || fd >= 65536 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = 0;
		if (glue(&arr[fd], buf) == -1)
			return (-1);
		ft_bzero(buf, BUFF_SIZE);
		if (ft_strchr(arr[fd], '\n'))
			break ;
	}
	if (size == 0 && arr[fd] == NULL)
		return (0);
	if (size == -1 || get_line(&arr[fd], line, 0) == -1 || *line == NULL)
		return (-1);
	return (1);
}
