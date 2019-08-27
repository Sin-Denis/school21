/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:56:23 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/26 12:17:17 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void game_params_init(t_game_params *params, int plr_id)
{
	params->_cycles_to_die = CYCLE_TO_DIE;
	params->_num_check = 0;
	params->_num_live_ops = 0;
	params->_num_cycle = 0;
	params->_player_id = plr_id;
}

void	vm_init(t_vm *vm)
{
	vm->_plrs = pol_vector_create(0, sizeof(t_player), player_destroy);
	vm->_cursors = pol_vector_create(0, sizeof(t_cursor), cursor_destroy);
	vm->_arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	vm->_dump = -1;
}

void	vm_start(t_vm *vm)
{
	game_params_init(&vm->_params,
	((t_player *)pol_vector_at(vm->_plrs, vm->_plrs->_size))->_id);
}
