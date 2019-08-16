/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:11:34 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/16 17:45:59 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	read_line(int fd, char *str[fd])
{
	char	*temp;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	ret = 0;
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = str[fd];
		if (!(str[fd] = ft_strjoin(str[fd], buff)))
			return (-1);
		free(temp);
	}
	return (ret);
}

static int	parse_str(int fd, char **line, char *str[fd], int flag)
{
	char	*temp;

	temp = str[fd];
	if (ft_strchr(temp, '\n'))
	{
		if (!(*line = ft_strsub(temp, 0, ft_strchr(temp, '\n') - temp)))
			return (-1);
	}
	else if (!(*line = ft_strdup(temp)))
		return (-1);
	if ((str[fd] = ft_strchr(str[fd], '\n')) == NULL)
		ft_bzero(str[fd], 0);
	else
	{
		str[fd]++;
		flag++;
	}
	if (str[fd] != NULL)
		if (!(str[fd] = ft_strdup(str[fd])))
			return (-1);
	free(temp);
	return (flag);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str[65536];
	int				flag;

	if (fd < 0 || fd >= 65536 || !line || BUFF_SIZE <= 0)
		return (-1);
	flag = 0;
	if (!str[fd])
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	ret = read_line(fd, str);
	if (ret == -1)
		return (-1);
	if (str[fd][0] != '\0')
		if ((flag = parse_str(fd, line, str, flag)) == -1)
			return (-1);
	if (str[fd] && !ret && flag == 0)
		return (0);
	return (1);
}
