/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:38 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:37:59 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	int		lenght;
	char	*new_s1;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	lenght = ft_strlen(s1);
	if (!(new_s1 = malloc(sizeof(char) * (lenght + 1))))
		return (0);
	while (i < lenght)
	{
		new_s1[i] = s1[i];
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}
