/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:25 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 10:27:14 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

t_stack			*stack_create(void)
{
	t_stack		*s;

	if ((s = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit(1);
	s->barrier = node_create(0);
	s->size = 0;
	return (s);
}
