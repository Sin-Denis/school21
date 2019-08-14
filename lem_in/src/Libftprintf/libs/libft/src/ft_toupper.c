/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:50:17 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/05 18:18:00 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

int			ft_toupper(int ch)
{
	if (ft_islower(ch))
		return (ch - 32);
	return ((unsigned int)ch);
}
