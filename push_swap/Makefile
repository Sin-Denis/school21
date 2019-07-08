CC := gcc

FLAGS := -Wall -Wextra -Werror

LIB_DIR := src/Libftprintf
LIB := $(LIB_DIR)/libftprintf.a
LIB_LINK := -L$(LIB_DIR) -lftprintf

STACK_INC := src/stack/inc/stack.h
VECTOR_INC := src/vector/inc/vector.h
PUSH_SWAP_INC := src/push_swap/inc/push_swap.h
CHECKER_INC := src/checker/inc/checker.h

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

VECTOR_FILES :=	create.c\
				destroy.c\
				get_elem.c\
				length.c\
				push_back.c\
				resize.c\
				set_elem.c\
				sort.c\

PUSH_SWAP_FILES := 	operations_calculate.c\
					order_calculate.c\
					error_exit.c\
					handler1.c\
					handler2.c\
					handler3.c\
					handler4.c\
					handler5.c\
					handler6.c\
					handler7.c\
					arguments_parse.c\
					sort.c\
					sort_three_elem.c\
					state_print.c\
					main.c\

CHECKER_FILES :=	mode_debug.c\
					mode_color.c\
					mode_default.c\
					arguments_parse.c\
					checker_support_functions.c\
					main.c\

STACK_SRC_DIR := src/stack/src
VECTOR_SRC_DIR := src/vector/src
PUSH_SWAP_SRC_DIR := src/push_swap/src
CHECKER_SRC_DIR := src/checker/src

STACK_SRC := $(addprefix $(STACK_SRC_DIR)/,$(STACK_FILES))
VECTOR_SRC := $(addprefix $(VECTOR_SRC_DIR)/,$(VECTOR_FILES))
PUSH_SWAP_SRC := $(addprefix $(PUSH_SWAP_SRC_DIR)/,$(PUSH_SWAP_FILES))
CHECKER_SRC := $(addprefix $(CHECKER_SRC_DIR)/,$(CHECKER_FILES))

STACK_OBJ_DIR := src/stack/obj
VECTOR_OBJ_DIR := src/vector/obj
PUSH_SWAP_OBJ_DIR := src/push_swap/obj
CHECKER_OBJ_DIR := src/checker/obj

STACK_OBJ := $(addprefix $(STACK_OBJ_DIR)/,$(STACK_FILES:.c=.o))
VECTOR_OBJ := $(addprefix $(VECTOR_OBJ_DIR)/,$(VECTOR_FILES:.c=.o))
PUSH_SWAP_OBJ := $(addprefix $(PUSH_SWAP_OBJ_DIR)/,$(PUSH_SWAP_FILES:.c=.o))
CHECKER_OBJ := $(addprefix $(CHECKER_OBJ_DIR)/,$(CHECKER_FILES:.c=.o))

all: directory $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(LIB) $(PUSH_SWAP_OBJ) $(STACK_OBJ) $(VECTOR_OBJ)
	@$(CC) $(FLAGS) $(STACK_OBJ) $(VECTOR_OBJ) $(PUSH_SWAP_OBJ) $(LIB_LINK) -o $@

$(CHECKER): $(LIB) $(CHECKER_OBJ) $(STACK_OBJ) $(VECTOR_OBJ)
	@$(CC) $(FLAGS) $(STACK_OBJ) $(VECTOR_OBJ) $(CHECKER_OBJ) $(LIB_LINK) -o $@

$(STACK_OBJ_DIR)/%.o: $(STACK_SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@

$(VECTOR_OBJ_DIR)/%.o: $(VECTOR_SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@

$(CHECKER_OBJ_DIR)/%.o: $(CHECKER_SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@

$(LIB):
	@make re -C $(LIB_DIR)

directory: $(STACK_OBJ_DIR) $(VECTOR_OBJ_DIR) $(PUSH_SWAP_OBJ_DIR) $(CHECKER_OBJ_DIR)

$(STACK_OBJ_DIR):
	@mkdir -p $(STACK_OBJ_DIR)

$(VECTOR_OBJ_DIR):
	@mkdir -p $(VECTOR_OBJ_DIR)

$(PUSH_SWAP_OBJ_DIR):
	@mkdir -p $(PUSH_SWAP_OBJ_DIR)

$(CHECKER_OBJ_DIR):
	@mkdir -p $(CHECKER_OBJ_DIR)

clean:
	@rm -rf $(STACK_OBJ_DIR) $(VECTOR_OBJ_DIR) $(PUSH_SWAP_OBJ_DIR) $(CHECKER_OBJ_DIR)
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -rf $(PUSH_SWAP) $(CHECKER)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re directory
