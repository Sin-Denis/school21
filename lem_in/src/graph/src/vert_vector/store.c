/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:49:07 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 14:03:33 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void	vert_vector_store(t_vert_vector *v, size_t idx, char *name)
{
	ft_strdel(&v->data[idx].name);
	v->data[idx].name = ft_strdup(name);
}
