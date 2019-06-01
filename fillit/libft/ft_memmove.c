/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:34:58 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:26:25 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	csrc = (char*)src;
	cdst = (char*)dst;
	i = -1;
	if (dst == src)
		return (dst);
	if (cdst > csrc)
		while ((int)(--len) >= 0)
			*(cdst + len) = *(csrc + len);
	else
		while (++i < len)
		{
			*(cdst + i) = *((unsigned char*)src + i);
		}
	return (cdst);
}
