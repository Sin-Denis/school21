/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pair.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:46:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/22 11:15:54 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_PAIR_H
#define VECTOR_PAIR_H

#include <stdlib.h>
#include "../../Libftprintf/libftprintf.h"

typedef	struct		s_pair
{
	int				first;
	int				second;
}					t_pair;

typedef struct		s_vector_pair
{
	t_pair			*data;
	int				size;
	int				capacity;
}					t_vector_pair;

/* t_vector_pair */
void				vector_pair_create(t_vector_pair **v, int size);
void				vector_pair_destroy(t_vector_pair **v);
void				vector_pair_push_back(t_vector_pair *v, int first, int second);
t_pair				vector_pair_at(t_vector_pair *v, int idx);
int					vector_pair_first(t_vector_pair *v, int idx);
int					vector_pair_second(t_vector_pair *v, int idx);
void				vector_pair_store(t_vector_pair *v, int idx, int first, int second);
int					vector_pair_len(t_vector_pair *v);
void				vector_pair_print(t_vector_pair *v);

#endif