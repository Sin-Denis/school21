# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 12:33:04 by nparker           #+#    #+#              #
#    Updated: 2019/08/17 14:20:20 by jblue-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
FLAGS := -Wall -Wextra -Werror -g

NAME := lem-in

LIB_DIR	:= src/Libftprintf
LIBLINK	:= -L$(LIB_DIR) -lftprintf
LIB := $(LIB_DIR)/libftprintf.a

SRC_DIR := src
MAIN_SRC_DIR := src
MAIN_FILES := main.c
MAIN_OBJ_DIR := objects
MAIN_INC := include/lem_in.h
DICT_SRC_DIR := $(SRC_DIR)/dictionary/src
ALGORITHM_SRC_DIR := $(SRC_DIR)/graph/src/algorithms
GRAPH_SRC_DIR := $(SRC_DIR)/graph/src/graph
VERT_VECTOR_SRC_DIR := $(SRC_DIR)/graph/src/vert_vector
PAIR_SRC_DIR := $(SRC_DIR)/pair/src
PAIR_DICT_SRC_DIR := $(SRC_DIR)/pair_dict/src
PARSING_SRC_DIR := $(SRC_DIR)/parsing/src
QUEUE_SRC_DIR := $(SRC_DIR)/queue/src
VECTOR_SRC_DIR := $(SRC_DIR)/vector/src
OUTPUT_SRC_DIR := src/output/src

DICT_INC := src/dictionary/include/dictionary.h
GRAPH_INC := src/graph/include/graph.h
PAIR_INC := src/pair/include/pair.h
PAIR_DICT_INC := src/pair_dict/include/p_dict.h
PARSING_INC := src/parsing/include/parse.h
QUEUE_INC := src/queue/include/queue.h
VECTOR_INC := src/vector/include/vector.h
OUTPUT_INC := src/output/include/output.h


DICT_FILES :=	at.c\
				delete.c\
				field_init.c\
				hash.c\
				init.c\
				insert.c\
				print.c\

ALGORITHM_FILES :=	optimized_solution.c\
					analysis.c\
					bfs.c\
					get_double_net.c\

GRAPH_FILES :=		add_vert.c\
					copy.c\
					edge.c\
					get_vert.c\
					get_weight.c\
					init.c\
					print.c\
					set_weight.c\

VERT_VECTOR_FILES :=	at.c\
						copy_vert_vec.c\
						init_vert_vec.c\
						print_vert_vec.c\
						push_back.c\
						size.c\
						store.c\
						vertex_init.c\

PAIR_FILES :=	at.c\
				create.c\
				delete.c\
				destory.c\
				length.c\
				pop_back.c\
				print.c\
				push_back.c\
				store.c\

PAIR_DICT_FILES :=	contains.c\
					delete.c\
					field_init.c\
					hash.c\
					init.c\
					insert.c\
					print.c\

PARSING_FILES :=	ft_count_digits.c\
					ft_isnum.c\
					misc.c\
					parse.c\
					check_line.c\
					parse_line.c\
					validate.c\

QUEUE_FILES :=	init.c\
				node_init.c\
				operations.c\

VECTOR_FILES :=	copy.c\
				create.c\
				destroy.c\
				get_elem.c\
				length.c\
				pop_back.c\
				print.c\
				push_back.c\
				resize.c\
				set_elem.c\
				sort.c\
				sum.c\

OUTPUT_FILES := output.c\
				distribution.c\
				get_roads.c\
				output_road_handler.c\

OBJ_DIR := objects


DICT_SRC := $(addprefix $(DICT_SRC_DIR)/,$(DICT_FILES))
GRAPH_SRC := $(addprefix $(GRAPH_SRC_DIR)/,$(GRAPH_FILES))
ALGORITHM_SRC := $(addprefix $(ALGORITHM_SRC_DIR)/,$(ALGORITHM_FILES))
VERT_VECTOR_SRC := $(addprefix $(VERT_VECTOR_SRC_DIR)/,$(VERT_VECTOR_FILES))
PAIR_SRC := $(addprefix $(PAIR_SRC_DIR)/,$(PAIR_FILES))
PAIR_DICT_SRC := $(addprefix $(PAIR_DICT_SRC_DIR)/,$(PAIR_DICT_FILES))
PARSING_SRC := $(addprefix $(PARSING_SRC_DIR)/,$(PARSING_FILES))
QUEUE_SRC := $(addprefix $(QUEUE_SRC_DIR)/,$(QUEUE_FILES))
VECTOR_SRC := $(addprefix $(VECTOR_SRC_DIR)/,$(VECTOR_FILES))
OUTPUT_SRC := $(addprefix $(OUTPUT_SRC_DIR)/,$(OUTPUT_FILES))

DICT_OBJ_DIR := src/dictionary/obj
GRAPH_OBJ_DIR := src/graph/obj
PAIR_OBJ_DIR := src/pair/obj
PAIR_DICT_OBJ_DIR := src/pair_dict/obj
PARSING_OBJ_DIR := src/parsing/obj
QUEUE_OBJ_DIR := src/queue/obj
VECTOR_OBJ_DIR := src/vector/obj
OUTPUT_OBJ_DIR := src/output/obj

MAIN_OBJ := $(addprefix $(MAIN_OBJ_DIR)/,$(MAIN_FILES:.c=.o))
DICT_OBJ := $(addprefix $(DICT_OBJ_DIR)/,$(DICT_FILES:.c=.o))
GRAPH_OBJ := $(addprefix $(GRAPH_OBJ_DIR)/,$(GRAPH_FILES:.c=.o))
ALGORITHM_OBJ := $(addprefix $(GRAPH_OBJ_DIR)/,$(ALGORITHM_FILES:.c=.o))
VERT_VECTOR_OBJ := $(addprefix $(GRAPH_OBJ_DIR)/,$(VERT_VECTOR_FILES:.c=.o))
PAIR_OBJ := $(addprefix $(PAIR_OBJ_DIR)/,$(PAIR_FILES:.c=.o))
PAIR_DICT_OBJ := $(addprefix $(PAIR_DICT_OBJ_DIR)/,$(PAIR_DICT_FILES:.c=.o))
PARSING_OBJ := $(addprefix $(PARSING_OBJ_DIR)/,$(PARSING_FILES:.c=.o))
QUEUE_OBJ := $(addprefix $(QUEUE_OBJ_DIR)/,$(QUEUE_FILES:.c=.o))
VECTOR_OBJ := $(addprefix $(VECTOR_OBJ_DIR)/,$(VECTOR_FILES:.c=.o))
OUTPUT_OBJ := $(addprefix $(OUTPUT_OBJ_DIR)/,$(OUTPUT_FILES:.c=.o))


##


all: directory $(NAME)

$(NAME): $(LIB) $(MAIN_OBJ)  $(PARSING_OBJ) $(ALGORITHM_OBJ) $(DICT_OBJ)  $(VERT_VECTOR_OBJ) $(GRAPH_OBJ) $(PAIR_OBJ)  $(QUEUE_OBJ) $(VECTOR_OBJ) $(OUTPUT_OBJ) $(PAIR_DICT_OBJ)
	@$(CC) -g $(FLAGS) -o $@  $(DICT_OBJ) $(GRAPH_OBJ)  $(ALGORITHM_OBJ) $(VERT_VECTOR_OBJ) $(PAIR_OBJ) $(QUEUE_OBJ) $(VECTOR_OBJ) $(OUTPUT_OBJ) $(PARSING_OBJ) $(MAIN_OBJ) $(PAIR_DICT_OBJ) $(LIB)



$(MAIN_OBJ_DIR)/%.o: $(MAIN_SRC_DIR)/%.c $(MAIN_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(DICT_OBJ_DIR)/%.o: $(DICT_SRC_DIR)/%.c $(DICT_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(PAIR_DICT_OBJ_DIR)/%.o: $(PAIR_DICT_SRC_DIR)/%.c $(PAIR_DICT_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(GRAPH_OBJ_DIR)/%.o: $(GRAPH_SRC_DIR)/%.c $(GRAPH_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(GRAPH_OBJ_DIR)/%.o: $(ALGORITHM_SRC_DIR)/%.c $(GRAPH_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(GRAPH_OBJ_DIR)/%.o: $(VERT_VECTOR_SRC_DIR)/%.c $(GRAPH_INC)
	@$(CC) $(FLAGS) -c $< -o $@



$(PAIR_OBJ_DIR)/%.o: $(PAIR_SRC_DIR)/%.c $(PAIR_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(PARSING_OBJ_DIR)/%.o: $(PARSING_SRC_DIR)/%.c $(PARSING_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(QUEUE_OBJ_DIR)/%.o: $(QUEUE_SRC_DIR)/%.c $(QUEUE_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(VECTOR_OBJ_DIR)/%.o: $(VECTOR_SRC_DIR)/%.c $(VECTOR_INC)
	@$(CC) $(FLAGS) -c $< -o $@

$(OUTPUT_OBJ_DIR)/%.o: $(OUTPUT_SRC_DIR)/%.c $(OUTPUT_INC)
	@$(CC) $(FLAGS) -c $< -o $@



$(LIB):
	@make -C $(LIB_DIR)

directory: $(MAIN_OBJ_DIR) $(DICT_OBJ_DIR) $(GRAPH_OBJ_DIR) $(PAIR_OBJ_DIR) $(PARSING_OBJ_DIR) $(QUEUE_OBJ_DIR) $(VECTOR_OBJ_DIR) $(OUTPUT_OBJ_DIR) $(ALGORITHM_OBJ_DIR) $(VERT_VECTOR_OBJ_DIR) $(PAIR_DICT_OBJ_DIR)

$(MAIN_OBJ_DIR):
	@mkdir -p $(MAIN_OBJ_DIR)
$(DICT_OBJ_DIR):
	@mkdir -p $(DICT_OBJ_DIR)

$(GRAPH_OBJ_DIR):
	@mkdir -p $(GRAPH_OBJ_DIR)

$(PAIR_OBJ_DIR):
	@mkdir -p $(PAIR_OBJ_DIR)
	
$(PAIR_DICT_OBJ_DIR):
	@mkdir -p $(PAIR_DICT_OBJ_DIR)

$(PARSING_OBJ_DIR):
	@mkdir -p $(PARSING_OBJ_DIR)

$(QUEUE_OBJ_DIR):
	@mkdir -p $(QUEUE_OBJ_DIR)

$(VECTOR_OBJ_DIR):
	@mkdir -p $(VECTOR_OBJ_DIR)

$(OUTPUT_OBJ_DIR):
	@mkdir -p $(OUTPUT_OBJ_DIR)

$(ALGORITHM_OBJ_DIR):
	@mkdir -p $(ALGORITHM_OBJ_DIR)

$(VERT_VECTOR_OBJ_DIR):
	@mkdir -p $(OUTPUT_OBJ_DIR)

clean:
	@rm -rf $(DICT_OBJ_DIR) $(GRAPH_OBJ_DIR) $(PAIR_OBJ_DIR) $(PARSING_OBJ_DIR) $(QUEUE_OBJ_DIR) $(VECTOR_OBJ_DIR) $(MAIN_OBJ_DIR) $(OUTPUT_OBJ_DIR) $(PAIR_DICT_OBJ_DIR)
	@make -C $(LIB_DIR) clean
	
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
