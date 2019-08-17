/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:11:14 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 15:59:32 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef	struct		s_qnode
{
	int				key;
	struct s_qnode	*prev;
	struct s_qnode	*next;
}					t_qnode;

typedef struct		s_int_queue
{
	t_qnode			*bar;
	size_t			size;
}					t_int_queue;

/*
**Functions t_qnode
*/
t_qnode				*qnode_create(int key);
void				qnode_destroy(t_qnode **node);

/*
**Functions t_queue
*/
t_int_queue			*int_queue_create(void);
void				int_queue_destroy(t_int_queue **q);
void				int_queue_push(t_int_queue *q, int key);
int					int_queue_pop(t_int_queue *q);
char				int_queue_isempty(t_int_queue *q);

#endif
