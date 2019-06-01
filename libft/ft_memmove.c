/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:59:36 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/13 20:00:58 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (tmp2 < tmp1)
	{
		tmp1 += (len - 1);
		tmp2 += (len - 1);
		while (len)
		{
			*tmp1 = *tmp2;
			tmp1--;
			tmp2--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
