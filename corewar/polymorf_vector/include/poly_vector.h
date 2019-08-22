/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_vector.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:54:53 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/22 20:06:25 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLY_VECTOR_H
#define POLY_VECTOR_H

#include <stdlib.h>

typedef struct	s_pol_vector
{
	void		*data;
	size_t		unit_size;
	size_t		size;
	size_t		cap;
}				t_pol_vector;

t_pol_vector	*pol_vector_create(size_t unit_size, size_t size)
{
	t_pol_vector	*v;

	v = (t_pol_vector *)malloc(sizeof(t_pol_vector) * size);
	if (size == 0)
	{
		
	}
	return (v);
}

#endif
