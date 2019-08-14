/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:23 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 14:45:32 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# define INCREASE_SIZE 2

# include "../../Libftprintf/libftprintf.h"

typedef int			t_vector_type;

typedef struct		s_vector
{
	t_vector_type	*data;
	int				size;
	int				capacity;
}					t_vector;

/* t_vector */
t_vector			*vector_create(int size);
void				vector_destroy(t_vector **v);
void				vector_resize(t_vector *v, int size);
t_vector_type		vector_get_elem(t_vector *v, int idx);
void				vector_set_elem(t_vector *v, int idx, t_vector_type val);
void				vector_push_back(t_vector *v, t_vector_type val);
int					vector_length(t_vector *v);
void				vector_print(t_vector *v);
void				vector_quick_sort(t_vector *v);
void				vector_copy(t_vector *dst, t_vector *src);
void				vector_pop_back(t_vector *v);
int					vector_get_sum(t_vector *v, int start, int end);

#endif
