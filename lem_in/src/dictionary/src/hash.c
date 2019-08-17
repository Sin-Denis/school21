/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:34:03 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 12:19:36 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"

size_t		hash(const char *key, int m, int k)
{
	size_t	i;
	int		a;
	size_t	hash_val;
	size_t	len;

	i = 0;
	a = 17;
	hash_val = 0;
	len = ft_strlen(key);
	while (i < len)
	{
		hash_val *= a;
		hash_val += key[i++];
	}
	hash_val += k;
	hash_val %= m;
	return (hash_val);
}
