/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:33:36 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:56:42 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_dict.h"

void	p_dict_print(t_p_dict *dict)
{
	int	i;

	i = -1;
	while ((size_t)++i < dict->capacity)
	{
		if (dict->data[i].status == EXIST)
			ft_printf("%d : %lld\n",
			dict->data[i].key->first, dict->data[i].key->second);
	}
}
