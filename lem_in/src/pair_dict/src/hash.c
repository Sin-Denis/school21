/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:34:03 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:50:31 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

size_t		p_hash(const t_pair *key, int m, int k)
{
	size_t	hash_val;

	hash_val = key->first * 17 * 17 + key->second * 17;
	hash_val += k;
	hash_val %= m;
	return (hash_val);
}
