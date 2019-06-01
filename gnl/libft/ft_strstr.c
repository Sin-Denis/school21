/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:37:06 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 18:14:04 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*tmp1;

	tmp1 = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (tmp1);
	while (*tmp1)
	{
		if (ft_strncmp(tmp1, needle, ft_strlen(needle)) == 0)
			return (tmp1);
		tmp1++;
	}
	return (NULL);
}
