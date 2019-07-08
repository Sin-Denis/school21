/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:38:40 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/08 09:38:41 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

void			node_destroy(t_node **node)
{
	(*node)->next = NULL;
	(*node)->prev = NULL;
	free(*node);
	*node = NULL;
}
