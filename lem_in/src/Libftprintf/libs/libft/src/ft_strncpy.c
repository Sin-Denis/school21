/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:39:25 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 18:08:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;

	s = dst;
	while (len > 0 && *src)
	{
		*s = *src;
		s++;
		src++;
		len--;
	}
	while (len > 0)
	{
		len--;
		*s = '\0';
		s++;
	}
	return (dst);
}
