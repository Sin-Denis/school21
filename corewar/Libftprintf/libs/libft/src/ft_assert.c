/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:36:50 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/14 15:31:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_assert(char const *actual, char const *expected)
{
	if (actual == NULL && expected == NULL)
		return (1);
	if (ft_strcmp(actual, expected) == 0)
		return (1);
	return (0);
}
