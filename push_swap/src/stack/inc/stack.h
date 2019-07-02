#ifndef STACK_H_
#define STACK_H_

#include "../../Libftprintf/libftprintf.h"

typedef struct		s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				order_idx;
	int				operations_amount;
	int				self_deep;
	int				appropriate_deep;
}					t_node;

typedef struct		s_stack
{
	t_node			*barrier;
	int				size;
}					t_stack;

t_node				*node_create(int value);
void				node_destroy(t_node **node);

t_stack				*stack_create(void);
void				stack_push_back(t_stack *s, int elem);
void				stack_push_front(t_stack *s, int elem);
void				stack_pop_back(t_stack *s);
void				stack_pop_front(t_stack *s);
void				stack_destroy(t_stack **s);
char				stack_is_empty(t_stack *s);
int					stack_swap(t_stack *s);
int					stack_shift(t_stack *a, t_stack *b);
int					stack_rotate(t_stack *s);
int					stack_reverse_rotate(t_stack *s);
int					stack_simultaneous_swap(t_stack *a, t_stack *b);
int					stack_simultaneous_rotate(t_stack *a, t_stack *b);
int					stack_simultaneous_reverse_rotate(t_stack *a, t_stack *b);
void				stack_print(t_stack *s);
void				stack_clean(t_stack *s);
t_node				*stack_top(t_stack *s);

#endif
