/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:05:19 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/26 12:03:51 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_cursor	*cursor_create(int id, int position, int user_id)
{
	t_cursor	*cur;

	cur = (t_cursor *)malloc(sizeof(t_cursor));
	cur->_cursor_id = id;
	cur->_position = position;
	cur->_carry = 0;
	cur->_reg[0] = user_id;
	return (cur);
}

void	cursor_destroy(void **cursor)
{
	t_cursor	**cur;

	cur = (t_cursor **)cursor;
	free(*cur);
	*cur = NULL;
}

void	cursor_print(void *cursor)
{
	t_cursor	*cur;

	cur = (t_cursor *)cursor;
	ft_printf("id: %d carry: %d curr_op: %d\
	cycle_last_live: %d cycle_delay: %d\
	position: %d trasition: %d", 
	cur->_cursor_id,
	cur->_carry,
	cur->_curr_op,
	cur->_cycle_last_live,
	cur->_cycle_delay,
	cur->_position,
	cur->_transition
	);
}
