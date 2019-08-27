/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champions_declaration.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:22:44 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/26 12:27:56 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void champion_declaration(t_player *plr)
{
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !",
		plr->_id,
		plr->_code_size,
		plr->_name,
		plr->_comment
	);
}

void	vm_champions_declaration(t_vm *vm)
{
	size_t i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < pol_vector_size(vm->_plrs))
	{
		champion_declaration(pol_vector_at(vm->_plrs, i));
		++i;
	}
}
