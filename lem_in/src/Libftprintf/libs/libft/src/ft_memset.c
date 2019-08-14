/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:53:28 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/03 18:40:51 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *cmp;

	cmp = (unsigned char *)b;
	while (len)
	{
		*cmp = (unsigned char)c;
		cmp++;
		len--;
	}
	return (b);
}
