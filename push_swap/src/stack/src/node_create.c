/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:37 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:38 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

t_node			*node_create(int value)
{
	t_node		*node;

	if ((node = (t_node *)malloc(sizeof(t_node))) == NULL)
		exit(1);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->order_idx = -1;
	node->operations_amount = 0;
	return (node);
}
