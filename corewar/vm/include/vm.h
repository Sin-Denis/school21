/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:17:28 by dmorar            #+#    #+#             */
/*   Updated: 2019/08/26 12:30:12 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
#define VM_H

#include "../../include/op.h"
#include "../../Libftprintf/libftprintf.h"
#include "../../polymorf_vector/include/pol_vector.h"

typedef struct		s_player
{
    int             _id;
	char			*_name;
	char			*_comment;
	unsigned char	*_ops;
	int				_len;
	int				_code_size;
}					t_player;

typedef struct      s_cursor
{
    int             _cursor_id;
    t_bool          _carry;
    int             _curr_op;
    int             _cycle_last_live;
    int             _cycle_delay;
    int             _position;
    int             _transition;
    int             _reg[REG_NUMBER];
}                   t_cursor;

typedef struct      s_game_params
{
    int             _player_id;
    int             _num_cycle;
    int             _num_live_ops;
    int             _cycles_to_die;
    int             _num_check;
}                   t_game_params;

typedef struct		s_vm
{
	t_pol_vector    *_plrs;
    t_pol_vector    *_cursors;
    unsigned char   *_arena;
    t_game_params   _params;
    char            _dump;
}					t_vm;

/*
** PLAYER_FUNCTIONS
*/
t_player            *player_create(int id, char *name, char *comment, unsigned char *ops);
void                player_destroy(void **player);
void                player_print(void *player);

/*
** CURSOR_FUNCTIONS
*/
t_cursor            *cursor_create(int id, int position, int user_id);
void                cursor_destroy(void **cursor);
void                cursor_print(void *cursor);

/*
** VM_FUNCTIONS
*/
t_bool				vm_cursor_exist(t_vm *vm);
void				vm_init(t_vm *vm);
void				vm_champions_declaration(t_vm *vm);
void				vm_output(t_vm *vm);
void                vm_start(t_vm *vm);
void				vm_end(t_vm *vm);
void                vm_run_cycle(t_vm *vm);
void                vm_print(t_vm *vm);

void                parsing(t_vm *vm, int argc, char **argv);

#endif
