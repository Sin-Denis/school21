/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:02:39 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:00 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_free(char *s1, char *s2, int n)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = NULL;
	res = ft_strnew(len1 + len2);
	if (res == NULL)
		return (NULL);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	if (n == 1)
		free(s1);
	else if (n == 2)
		free(s2);
	else if (n == 3)
	{
		free(s1);
		free(s2);
	}
	return (res);
}
