/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:24:01 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/13 20:01:06 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (n)
	{
		*tmp1 = *tmp2;
		tmp1++;
		tmp2++;
		n--;
	}
	return (dst);
}
