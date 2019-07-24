/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:24:49 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 13:24:50 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Graph_create(t_Graph **g)
{
	(*g) = (t_Graph *)malloc(sizeof(t_Graph));
	Hash_table_create(&(*g)->table);
	(*g)->start_id = NULL;
	(*g)->end_id = NULL;
	(*g)->size = 0;
}
