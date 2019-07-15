/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:59:46 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 15:33:39 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <stdlib.h>

struct	s_vertex;

typedef struct		s_vector
{
	struct s_vertex	*data;
	size_t			size;
	size_t			capacity;
}					t_vector;

typedef struct		s_vertex
{
	char			*name;
	t_vector		*adj;
}					t_vertex;

typedef struct		s_graph
{
	t_vector		*vert;
}					t_graph;

void			graph_create(t_graph **g);
void			graph_destroy(t_graph **g);

#endif
