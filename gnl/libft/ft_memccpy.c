/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:03:52 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 17:51:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (n)
	{
		*tmp1 = *tmp2;
		if (*tmp2 == (unsigned char)c)
		{
			tmp1++;
			return (dst + 1);
		}
		tmp1++;
		tmp2++;
		dst++;
		n--;
	}
	return (NULL);
}
