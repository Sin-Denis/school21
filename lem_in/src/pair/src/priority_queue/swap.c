/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:06:29 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 11:07:21 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pair.h"

void		pair_swap(t_pair *first, t_pair *second)
{
	t_pair	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}
