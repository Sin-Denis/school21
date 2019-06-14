/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:23:49 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/04 18:33:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
