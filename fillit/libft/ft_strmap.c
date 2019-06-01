/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:18:33 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:26:46 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	new_str = ft_strnew(ft_strlen(s));
	i = 0;
	if (!new_str)
		return (NULL);
	while (*(s + i))
	{
		*(new_str + i) = f(*(s + i));
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}
