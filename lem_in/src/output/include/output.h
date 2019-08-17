/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:54:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:28:42 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include "../../Libftprintf/libftprintf.h"
# include "../../pair/include/pair.h"
# include "../../graph/include/graph.h"
# include "../../vector/include/vector.h"

void				output(t_graph *g, t_string *str);
int					get_num_roads(t_graph *g);
t_vector			**get_all_roads(t_graph *g, int num_roads);
t_vector			*get_distribution(t_vector **roads,
								int num_ants, int num_roads);
void				road_handler(t_graph *g, t_vector *road,
								t_pair *indexes, t_pair *distr_offset);

#endif
