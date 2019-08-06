/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:54:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/06 13:12:48 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "../../Libftprintf/libftprintf.h"
#include "../../pair/include/pair.h"
#include "../../graph/include/graph.h"
#include "../../vector/include/vector.h"

void	output(t_graph *g, t_vector **roads, t_vector *distribution, int num_roads);

#endif
