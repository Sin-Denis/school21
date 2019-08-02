/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:20:49 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/02 13:38:13 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

t_qnode		*qnode_create(int key)
{
	t_qnode	*node;

	node = (t_qnode *)malloc(sizeof(t_qnode));
	node->key = key;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void		qnode_destroy(t_qnode **node)
{
	free(*node);
	*node = NULL;
}
