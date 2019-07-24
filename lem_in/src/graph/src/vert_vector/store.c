/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:30:19 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/24 16:03:07 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	Vert_vector_store(t_Vert_vector *v, size_t idx, char *name)
{
	v->data[idx].id = ft_strdup(name);
	v->data[idx].status = EXIST;
}
