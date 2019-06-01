/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr2alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:25:23 by jblue-da          #+#    #+#             */
/*   Updated: 2019/05/13 12:16:20 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_arr2alloc(int n, int m)
{
	int i;
	int **arr;

	i = 0;
	if (!(arr = (int **)malloc(sizeof(int *) * n)))
		return (NULL);
	while (i < n)
	{
		if (!(arr[i] = (int *)malloc(sizeof(int) * m)))
			return (NULL);
		++i;
	}
	return (arr);
}
