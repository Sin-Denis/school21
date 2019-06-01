/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:00:25 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:32 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			queue_destroy(t_queue *q)
{
	t_iterator	i;
	t_iterator	i_del;

	i = first(q);
	while (i.node)
	{
		i_del = i;
		next(&i);
		queue_del(q, &i_del);
	}
}
