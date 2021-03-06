/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:42:23 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/26 13:31:49 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

typedef struct	s_vector
{
	char		*name;
	int			age;
}				t_person;

void			person_destroy(void *p)
{
	free(((t_person *)p)->name);
}

int main(int argc, char **argv)
{
	t_vm vm;

	vm_init(&vm);
	parsing(&vm, argc, argv);
	vm_start(&vm);
	vm_champions_declaration(&vm);
	while (vm_cursor_exist(&vm) > 0)
		run_cycle(&vm);
	vm_output(&vm);
	vm_end(&vm);
	return (0);
}
