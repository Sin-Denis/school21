/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:41:08 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/26 12:16:25 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_player	*player_create(int id, char *name, char *comment, unsigned char *ops)
{
	t_player	*player;
	size_t		ops_len;

	player->_id = id;
	player = (t_player *)malloc(sizeof(t_player));
	player->_name = (name == NULL) ? NULL : ft_strdup(name);
	player->_comment = (comment == NULL) ? NULL : ft_strdup(comment);
	if (ops == NULL)
		player->_ops = NULL;
	else
	{
		ops_len = ft_strlen(ops);
		player->_ops = (unsigned char *)ft_memalloc(ops_len);
		ft_memmove(player->_ops, ops, ops_len);
	}
	return (player);
}

void	cursor_destroy(void **player)
{
	t_player	**plr;

	plr = (t_player **)player;
	free(*plr);
	*plr = NULL;
}

void	cursor_print(void *player)
{
	t_player	*plr;

	plr = (t_player *)player;
	ft_printf("id: %d name: %s comment: %s", plr->_id, plr->_name, plr->_comment);
}
