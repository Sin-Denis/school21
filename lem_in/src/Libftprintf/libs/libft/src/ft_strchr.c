/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:36:52 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/13 20:02:51 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *tmp;

	tmp = (char *)s;
	while (*tmp && *tmp != (char)c)
		tmp++;
	if (*tmp == (char)c || *tmp != 0)
		return (tmp);
	return (NULL);
}
