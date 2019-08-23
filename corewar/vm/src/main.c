/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:42:23 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/23 15:06:33 by jblue-da         ###   ########.fr       */
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

int main(void)
{
	// t_vm vm;
	
	// parsing(&vm, argc, argv);
	// vm_init(&vm);
	// vm_greating(&vm);
	// while (vm_cursor_exist(&vm) > 0)
	// 	run_cycle(&vm);
	// vm_output(&vm);
	// vm_end(&vm);

	t_pol_vector *v;

	v = pol_vector_create(0, sizeof(t_person));

	pol_vector_destroy(&v, person_destroy);
	return (0);	
}
