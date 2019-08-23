# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 12:33:04 by nparker           #+#    #+#              #
#    Updated: 2019/08/23 14:55:48 by jblue-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
FLAGS := -Wall -Wextra -Werror

VM := corewar
ASM := asm

LIB_DIR	:= Libftprintf
LIBLINK	:= -L$(LIB_DIR) -lftprintf
LIB := $(LIB_DIR)/libftprintf.a

VM_MAIN_SRC_DIR := vm/src
VM_VM_SRC_DIR := vm/src/vm
VM_PARSING_SRC_DIR := vm/src/parsing

VM_MAIN_

VM_OBJ_DIR := vm/obj
	
VM_INC := vm/inc/vm.h

VM_MAIN_FILE := main.c

VM_VM_FILES :=	run_cycle.c\

VM_PARSING_FILES :=	parsing.c\

VM_VM_SRC := $(addprefix $(VM_VM_SRC_DIR)/,$(VM_VM_FILES))
VM_PARSING_SRC := $(addprefix $(VM_PARSING_SRC_DIR)/,$(VM_PARSING_FILES))
VM_MAIN_SRC := $(addprefix $(VM_MAIN_SRC_DIR),$(VM_MAIN_FILE))

VM_SRC := $(VM_MAIN_SRC) $(VM_PARSING_SRC) $(VM_VM_SRC)
VM_OBJ := $(addprefix $(VM_OBJ_DIR)/,$(VM_MAIN_FILE:.c=.o) $(VM_VM_FILES:.c=.o) $(VM_PARSING_FILES:.c=.o))

all: directory $(VM)

$(VM): $(LIB) $(VM_OBJ)
	$(CC) $(FLAGS) -o $@ $(VM_OBJ)

$(VM_OBJ_DIR)/%.o: $(VM_VM_SRC_DIR)/%.c $(VM_INC)
	$(CC) $(FLAGS) -o $< -o $@

$(VM_OBJ_DIR)/%.o: $(VM_PARSING_SRC_DIR)/%.c $(VM_INC)
	$(CC) $(FLAGS) -o $< -o $@

$(VM_OBJ_DIR)/%.o: $(VM_MAIN_SRC_DIR)/%.c $(VM_INC)
	$(CC) $(FLAGS) -o $< -o $@

$(LIB):
	@make -C $(LIB_DIR)

directory: $(VM_OBJ_DIR)

$(VM_OBJ_DIR):
	@mkdir -p $(VM_OBJ_DIR)

clean:
	@rm -rf $(VM_OBJ_DIR)
	@make -C $(LIB_DIR) clean
	
fclean: clean
	@rm -f $(VM)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
