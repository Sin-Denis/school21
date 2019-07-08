/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:47 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:48 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

void		stack_print(t_stack *s)
{
	int		i;
	t_node	*iter;

	i = -1;
	iter = s->barrier->prev;
	while (++i < s->size)
	{
		ft_printf("%d\n", iter->value);
		iter = iter->prev;
	}
}
