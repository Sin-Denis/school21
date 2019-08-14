/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:23:13 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 18:17:46 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	return (0);
}

int			ft_tolower(int ch)
{
	if (ft_isupper(ch))
		return (ch + 32);
	return (ch);
}
