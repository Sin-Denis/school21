/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:46:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/31 13:45:10 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
#define PAIR_H

#include <stdlib.h>
#include "../../Libftprintf/libftprintf.h"

typedef struct		s_pair
{
	int				first;
	long long		second;
}					t_pair;

typedef struct		s_vector_pair
{
	t_pair			*data;
	size_t			size;
	size_t			capacity;
}					t_vector_pair;

typedef struct		s_priority_queue
{
	t_vector_pair	*v;
}					t_priority_queue;

/* t_vector_pair */
t_vector_pair		*vector_pair_create(int size);
void				vector_pair_destroy(t_vector_pair **v);
void				vector_pair_push_back(t_vector_pair *v, int first, long long second);
void				vector_pair_pop_back(t_vector_pair *v);
t_pair				*vector_pair_at(t_vector_pair *v, int idx);
int					vector_pair_first(t_vector_pair *v, int idx);
long long			vector_pair_second(t_vector_pair *v, int idx);
void				vector_pair_store(t_vector_pair *v, int idx, int first, long long second);
size_t				vector_pair_len(t_vector_pair *v);
void				vector_pair_print(t_vector_pair *v);
void				vector_pair_del(t_vector_pair *v, int key);

/* t_priority_queue */
t_priority_queue	*pq_create(void);
void				pq_destroy(t_priority_queue **q);
void				pq_insert(t_priority_queue *q, int first, long long second);
int					pq_min(t_priority_queue *q);
void				pq_extract_min(t_priority_queue *q);
void				pq_sift_dawn(t_priority_queue *q, int idx);
void				pq_sift_up(t_priority_queue *q, int idx);
void				pq_decrease(t_priority_queue *q, int first, long long second);
char				pq_isempty(t_priority_queue *q);
void				pair_swap(t_pair *first, t_pair *second);

#endif
