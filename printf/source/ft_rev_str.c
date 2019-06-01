/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:25:43 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:53 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_rev_str(char *str)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	res = ft_strnew(len);
	res[len] = '\0';
	while (len-- > 0)
		res[len] = str[i++];
	return (res);
}
