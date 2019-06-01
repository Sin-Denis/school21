/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:06 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:37:57 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	i = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	while (++i < len)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}
