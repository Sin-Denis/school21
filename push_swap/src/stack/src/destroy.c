/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:27 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:28 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

void			stack_destroy(t_stack **s)
{
	int			i;
	int			stack_size;

	i = -1;
	stack_size = (*s)->size;
	while (++i < stack_size)
		stack_pop_front(*s);
	node_destroy(&(*s)->barrier);
	free(*s);
	*s = NULL;
}
