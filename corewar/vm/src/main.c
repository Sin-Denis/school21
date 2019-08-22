/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:42:23 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/22 20:10:21 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int main(int argc, char **argv)
{
	t_vm vm;
	
	parsing(&vm, argc, argv);
	game_init(&vm);
	while (pol_vector_size(vm.cursors) > 0)
		execute_cycle(&vm);
	game_output(&vm);
	return (0);	
}
