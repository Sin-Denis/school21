/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:24:51 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 13:24:52 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Graph_destroy(t_Graph **g)
{
	Hash_table_destroy(&(*g)->table);
	ft_strdel(&(*g)->start_id);
	ft_strdel(&(*g)->end_id);
	free((*g));
	*g = NULL;
}