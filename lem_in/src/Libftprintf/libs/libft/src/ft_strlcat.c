/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:04:33 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/12 16:02:20 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_range(char *begin, size_t size)
{
	char		*tmp;

	tmp = begin;
	while (*tmp && size)
	{
		tmp++;
		size--;
	}
	return (tmp - begin);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tmp1;
	char		*tmp2;
	size_t		dst_len;
	size_t		free_mem;

	tmp1 = dst;
	tmp2 = (char *)src;
	dst_len = get_range(dst, size);
	free_mem = size - dst_len;
	if (free_mem == 0)
		return (dst_len + ft_strlen(src));
	tmp1 += dst_len;
	while (*tmp2)
	{
		if (free_mem != 1)
		{
			*tmp1 = *tmp2;
			tmp1++;
			free_mem--;
		}
		tmp2++;
	}
	*tmp1 = '\0';
	return (dst_len + (tmp2 - src));
}
