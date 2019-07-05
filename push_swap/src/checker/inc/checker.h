#ifndef CHECKER_H
#define CHECKER_H

#include "../../stack/inc/stack.h"
#include "../../vector/inc/vector.h"
#include "../../Libftprintf/libftprintf.h"

void	mode_debug(t_stack *a, t_stack *b);
void	mode_default(t_stack *a, t_stack *b);

void	checker_error_exit(t_stack *a, t_stack *b, char *operation);
void	error_handler_unary(t_stack *a, t_stack *b, char *operation, int (*f)(t_stack *));
void	error_handler_binary(t_stack *a, t_stack *b, char *operation, int (*f)(t_stack *, t_stack *));
void	operations_handler(t_stack *a, t_stack *b, char *operation);
int		operation_is_not_exist(char *op);

int		arguments_parse(t_stack *a, int argc, char **argv);

#endif
