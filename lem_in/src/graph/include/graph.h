/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:59:46 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 15:44:35 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <stdlib.h>
# include "../../vector/include/vector.h"
# define HASH_TABLE_INIT_SIZE 50

typedef enum		e_status
{
	BLANK = 0,
	DELETE = 1,
	EXIST = 2
}					t_status;

typedef struct		s_Vertex
{
	char			*id;
	t_vector		*adj;
	t_status		status;
}					t_Vertex;

typedef struct		s_Vert_vector
{
	t_Vertex		*data;
	size_t			size;
	size_t			capacity;
}					t_Vert_vector;

typedef struct		s_Hash_table
{
	t_Vert_vector	*data;
	size_t			size;
}					t_Hash_table;

typedef struct		s_Graph
{
	t_Hash_table	*table;
	size_t			start_id;
	size_t			end_id;
	size_t			size;
}					t_Graph;

/* Functions t_Vector */
void				Vert_vector_create(t_Vert_vector **v);
void				Vert_vector_create_size(t_Vert_vector **v, size_t size);
void				Vert_vector_destroy(t_Vert_vector **v);
void				Vert_vector_push_back(t_Vert_vector *v, char *name);
t_Vertex			*Vert_vector_at(t_Vert_vector *v, size_t idx);
void				Vert_vector_store(t_Vert_vector *v, size_t idx, char *name);
size_t				Vert_vector_size(t_Vert_vector *v);
void				Vert_vector_print(t_Vert_vector *v);

/* Functions t_Hash_table */
size_t				hash(char *key, int m, int k);
void				Hash_table_create(t_Hash_table **t);
void				Hash_table_destroy(t_Hash_table **t);
int					key_has(t_Hash_table *t, char *key);
void				key_add(t_Hash_table *t, char *key);
int					key_delete(t_Hash_table *t, char *key);
size_t				Hash_table_size(t_Hash_table *t);

/* Fucntions t_Graph */
void				Graph_create(t_Graph **g);
void				Graph_destroy(t_Graph **g);
void				Graph_add_vert(t_Graph *g, char *name);
void				Graph_add_edge(t_Graph *g, char *name1, char *name2);

#endif
