/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:35 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 11:13:59 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

int			stack_is_sort(t_stack *s)
{
	int		i;
	t_node	*iter;

	i = 0;
	iter = s->barrier->prev;
	while (++i < s->size)
	{
		if (iter->value > iter->prev->value)
			return (0);
		iter = iter->prev;
	}
	return (1);
}
