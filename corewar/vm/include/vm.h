/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:17:28 by dmorar            #+#    #+#             */
/*   Updated: 2019/08/22 20:09:02 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
#define VM_H

#include "../../include/op.h"
#include "../../polymorf_vector/include/poly_vector.h"

typedef struct		s_players
{
	char			*name;
	char			*comment;
	unsigned char	*ops;
	int				len;
	int				code_size;
	
}					t_players;

typedef struct      s_cursor
{
    int             cursor_id;
    char            carry;
    int             curr_op;
    int             cycle_last_live;
    int             cycle_delay;
    int             position;
    int             transition;
    int             reg[16];
}                   t_cursor;

typedef struct      s_game_params
{
    int             player_id;
    int             num_cycle;
    int             num_live_ops;
    int             cycles_to_die;
    int             num_check;
    unsigned char   *arena;
}                   t_game_params;

typedef struct		s_vm
{
	t_players		*plrs;
    t_pol_vector    *cursors;
    t_game_params   params;
    char            dump_exist;
}					t_vm;

void                parsing(t_vm *vm, int argc, char **argv);
void                execute_cycle(t_vm *vm);

#endif
