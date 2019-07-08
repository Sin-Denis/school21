/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:17 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:18 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

void		stack_clean(t_stack *s)
{
	int		i;
	int		stack_size;

	i = -1;
	stack_size = s->size;
	while (++i < stack_size)
		stack_pop_back(s);
}
