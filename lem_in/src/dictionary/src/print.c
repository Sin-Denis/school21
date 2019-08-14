/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:33:36 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 13:00:20 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"

void	dict_print(t_dict *dict)
{
	int	i;

	i = -1;
	while ((size_t)++i < dict->capacity)
	{
		if (dict->data[i].status == EXIST)
			ft_printf("%s: %d\n", dict->data[i].key, dict->data[i].val);
	}
}
