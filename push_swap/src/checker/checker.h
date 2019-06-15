#ifndef CHECKER_H
#define CHECKER_H

#include "../stack/inc/stack.h"
#include "../Libftprintf/libftprintf.h"

void	mode_color(t_stack *a, t_stack *b);
void	mode_debug(t_stack *a, t_stack *b);
void	mode_default(t_stack *a, t_stack *b);

int		arguments_parse(t_stack *a, int argc, char **argv);



#endif
