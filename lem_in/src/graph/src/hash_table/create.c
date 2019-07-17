/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:55:13 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/17 08:04:22 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void    Hash_table_create(t_Hash_table **t)
{
    (*t) = (t_Hash_table *)malloc(sizeof(t_Hash_table));
    Vert_vector_create_size(&(*t)->data, HASH_TABLE_INIT_SIZE);
    (*t)->capacity = HASH_TABLE_INIT_SIZE;
    (*t)->size = 0;
}
