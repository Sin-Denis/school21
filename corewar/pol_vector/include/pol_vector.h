/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pol_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:42:44 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/23 14:58:56 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POL_VECTOR_H
#define POL_VECTOR_H

#include <stdlib.h>
#include "../../Libftprintf/libftprintf.h"

typedef struct	s_pol_vector
{
	void		*_data;
	size_t 		_obj_size;
	size_t 		_size;
	size_t 		_cap;
}				t_pol_vector;

t_pol_vector	*pol_vector_create(size_t size, size_t obj_size);
void			pol_vector_destroy(t_pol_vector **v, void (*obj_destroy)(void *));
void			pol_vector_push_back(t_pol_vector *v, void *key);
void			pol_vector_size(t_pol_vector *v);
t_bool			pol_vector_empty(t_pol_vector *v);
void			*pol_vector_at(t_pol_vector *v, size_t idx);
void			pol_vector_print(t_pol_vector *v, void (*obj_print)(void *));

#endif
