/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/16 15:39:02 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int					main(void)
{
	t_Hash_table	*t;

	Hash_table_create(&t);
	key_add(t, "start");
	key_add(t, "end");
	key_add(t, "234");
	key_add(t, "1");
	Vert_vector_print(t->data);
	ft_printf("%d\n", key_has(t, "start"));
	Hash_table_destroy(&t);
	return (0);
}
