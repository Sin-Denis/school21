#ifndef CHECKER_H
#define CHECKER_H

#include "../stack/stack.h"
#include "unistd.h"

void	mode_color(t_stack *a, t_stack *b);
void	mode_debag(t_stack *a, t_stack *b);
void	mode_default(t_stack *a, t_stack *b);

int		arguments_parse(t_stack *a, int argc, char **argv);
int		instruction_parse(char **instrunction);
int		instructions_parse(char ***instructions);
void	stacks_status_print(t_stack *a, t_stack *b, int color);

#endif
