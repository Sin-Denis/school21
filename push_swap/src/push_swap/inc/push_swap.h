/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:40:03 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/15 10:31:57 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../stack/inc/stack.h"
# include "../../vector/inc/vector.h"
# include "../../Libftprintf/libftprintf.h"

int		arguments_parse(t_stack *a, int argc, char **argv);
void	error_exit(t_stack *a, t_stack *b);
void	order_calculate(t_stack *s);
t_node	*get_first_idx_node(t_stack *s);
void	come_back(t_stack *s);
void	come_back_rev(t_stack *s);
void	deep_set(t_stack *s);
void	operations_calculate(t_stack *a, t_stack *b);
void	sort_three_elem(t_stack *a);
void	sort(t_stack *a, t_stack *b);
void	state_print(t_stack *a, t_stack *b);
void	handler1(t_stack *a, t_stack *b, t_node *node);
void	handler2(t_stack *a, t_stack *b, t_node *node);
void	handler3(t_stack *a, t_stack *b, t_node *node);
void	handler4(t_stack *a, t_stack *b, t_node *node);
void	handler5(t_stack *a, t_stack *b, t_node *node);
void	handler6(t_stack *a, t_stack *b, t_node *node);
void	handler7(t_stack *a, t_stack *b, t_node *node);

#endif
