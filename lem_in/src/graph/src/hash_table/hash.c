/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:14:38 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/18 09:49:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

size_t	hash(char *key, int m, int k)
{
    size_t i;
    int a;
    size_t hash_val;
    size_t len;

    i = 0;
    a = 17;
    hash_val = 0;
    len = ft_strlen(key);
    while (i < len)
    {
        hash_val *= a;
        hash_val += key[i++];
    }
    hash_val %= m;
    hash_val += k;
    return (hash_val);
}
