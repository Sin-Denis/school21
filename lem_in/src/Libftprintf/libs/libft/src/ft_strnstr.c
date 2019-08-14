/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:37:06 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 18:10:49 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp1;
	size_t	size_needle;

	tmp1 = (char *)haystack;
	size_needle = ft_strlen(needle);
	if (ft_strlen(needle) == 0)
		return (tmp1);
	while (len && *tmp1)
	{
		if (ft_strncmp(tmp1, needle, ft_strlen(needle)) == 0\
		&& size_needle <= len)
			return (tmp1);
		tmp1++;
		len--;
	}
	return (NULL);
}
