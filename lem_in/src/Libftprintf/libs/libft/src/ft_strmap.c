/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:05:11 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 18:06:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = (*f)(s[i]);
		++i;
	}
	str[i] = '\0';
	return (str);
}
