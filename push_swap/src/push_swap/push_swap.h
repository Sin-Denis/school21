#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../stack/inc/stack.h"
#include "../vector/vector.h"
#include "../Libftprintf/libftprintf.h"

int		arguments_parse(t_stack *a, int argc, char **argv);
void	error_exit(t_stack *a, t_stack *b);
void    order_calculate(t_stack *s);
void	sort_three_elem(t_stack *a);
void    sort(t_stack *a, t_stack *b);

#endif