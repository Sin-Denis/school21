CC := gcc

FLAGS := -Wall -Wextra -Werror

LIB := src/Libftprintf/libftprintf.a

PUSH_SWAP := push_swap

CHECKER := checker

STACK_FILES := 	clean.c\
				create.c\
				destroy.c\
				front.c\
				is_empty.c\
				is_sort.c\
				node_create.c\
				node_destroy.c\
				pop_back.c\
				pop_front.c\
				print.c\
				push_back.c\
				push_front.c\
				reverse_rotate.c\
				rotate.c\
				shift.c\
				simultaneous_reverse_rotate.c\
				simultaneous_rotate.c\
				simultaneous_swap.c\
				swap.c\
				top.c\

STACK_DIR := src/stack/src

STACK_SRC := $(addprefix $(STACK_DIR)/,$(STACK_FILES))

VECTOR_FILES :=	create.c\
				destroy.c\
				get_elem.c\
				length.c\
				push_back.c\
				resize.c\
				set_elem.c\
				sort.c\

VECTOR_DIR := src/vector/src

VECTOR_SRC := $(addprefix $(VECTOR_DIR)/,$(VECTOR_FILES))

PUSH_SWAP_FILES := 	calculate/operations_calculate.c\
					calculate/order_calculate.c\
					error_control/error_exit.c\
					handlers/handler1.c\
					handlers/handler2.c\
					handlers/handler3.c\
					handlers/handler4.c\
					handlers/handler5.c\
					handlers/handler6.c\
					handlers/handler7.c\
					parsing/arguments_parse.c\
					sort/sort.c\
					sort/sort_three_elem.c\
					sort/state_print.c\
					main.c\

PUSH_SWAP_DIR := src/push_swap/src

PUSH_SWAP_SRC := $(addprefix $(PUSH_SWAP_DIR)/,$(PUSH_SWAP_FILES))

CHECKER_FILES :=	mode_debug/mode_debug.c\
					mode_default/mode_default.c\
					parsing/arguments_parse.c\
					support_functions/checker_support_functions.c\
					main.c\

CHECKER_DIR := src/checker/src

CHECKER_SRC := $(addprefix $(CHECKER_DIR)/,$(CHECKER_FILES))

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):
	$(CC) $(FLAGS) $(STACK_SRC) $(VECTOR_SRC) $(LIB) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP)

$(CHECKER):
	$(CC) $(FLAGS) $(STACK_SRC) $(VECTOR_SRC) $(LIB) $(CHECKER_SRC) -o $(CHECKER)

fclean:
	rm -rf $(PUSH_SWAP) $(CHECKER)

re: fclean all
