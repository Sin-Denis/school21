/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:03:51 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/13 20:12:22 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == ',' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char		*ft_strtrim(char const *s)
{
	char	*begin;
	char	*end;
	char	*res;
	int		len;

	if (s == NULL)
		return (NULL);
	begin = (char *)s;
	end = (char *)s + ft_strlen(s) - 1;
	while (ft_iswhitespace(*end) && end != begin)
		end--;
	while (ft_iswhitespace(*begin) && *begin)
		begin++;
	len = max(0, end - begin + 1);
	if (len == 0)
	{
		if ((res = (char *)malloc(sizeof(char) * 1)) == NULL)
			return (NULL);
	}
	else
		res = ft_strsub(s, begin - s, len);
	if (res == NULL)
		return (NULL);
	res[len] = 0;
	return (res);
}
