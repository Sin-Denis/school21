/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:04:08 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 17:50:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	mem = (unsigned char *)malloc(size);
	if (mem == NULL)
		return (NULL);
	while (i < size)
		mem[i++] = 0;
	return (mem);
}
