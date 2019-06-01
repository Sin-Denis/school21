/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:23:49 by jblue-da          #+#    #+#             */
/*   Updated: 2018/11/22 18:49:14 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		size;

	size = 0;
	while (*str != 0)
	{
		size++;
		str++;
	}
	return (size);
}

char		*ft_strdup(char *src)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	res = malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		res[i] = src[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
