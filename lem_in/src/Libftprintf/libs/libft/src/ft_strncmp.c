/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:37:00 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 18:08:24 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && *tmp1 && *tmp2 && *tmp1 == *tmp2)
	{
		tmp1++;
		tmp2++;
		n--;
	}
	return (*tmp1 - *tmp2);
}
