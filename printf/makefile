# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nparker <nparker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 13:24:28 by nparker           #+#    #+#              #
#    Updated: 2019/04/30 13:54:25 by nparker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := libftprintf.a

FLAGS := -Wall -Wextra -Werror

SRC_DIR := source/

SRC :=	cust_str_ops.c\
		str_at.c \
		str_create_custstr.c\
		str_create_size.c \
		str_create_str.c\
		str_custjoin.c \
		str_cut.c\
		str_destroy.c \
		str_forward.c\
		str_len.c\
		str_print.c \
		str_pushchar.c\
		str_pushstr.c \
		str_push_cs.c\
		str_resize.c \
		str_rev.c\
		to_cstr.c \
		fs_copy.c\
		fs_destroy.c \
		fs_init.c\
		fs_vector_create.c \
		fs_vector_destroy.c\
		fs_vector_length.c \
		fs_vector_push_back.c\
		fs_vector_resize.c \
		cast.c\
		c_handler.c \
		d_handler.c\
		f_handler.c \
		handler.c\
		lf_handler.c \
		o_handler.c\
		precision_handler.c \
		pr_handler.c\
		p_handler.c\
		sign_ops.c \
		s_handler.c\
		u_handler.c \
		width_handler.c\
		x_handler.c \
		bignum_create.c\
		bignum_create_by_str.c \
		bignum_destroy.c \
		bin_div.c\
		bin_mult.c \
		bin_sum.c\
		bin_to_dec.c \
		dec_div.c\
		dec_mult.c \
		dec_sum.c\
		get_bits.c \
		pos_pow.c\
		round.c \
		swap_comp_str.c \
		arr_zero.c\
		find_flags.c \
		get_flags.c\
		get_fs.c \
		get_precision.c\
		get_size.c \
		get_type.c\
		get_width.c \
		overflow_handle.c\
		parse.c \
		process_fs.c \
		prepare.c\
		prepare_flags.c \
		prepare_precision.c\
		prepare_size.c \
		fetch.c\
		iterators.c \
		queue_create.c\
		queue_destroy.c \
		queue_is_empty.c\
		queue_len.c \
		queue_pop.c\
		queue_push.c \
		store.c \
		find_exclusion.c\
		ft_abs.c \
		ft_bzero.c \
		ft_count_digits.c\
		ft_dec_to_hex.c \
		ft_dec_to_oct.c\
		ft_isalnum.c \
		ft_isalpha.c\
		ft_isdigit.c \
		ft_ltoa.c\
		ft_max.c \
		ft_pow.c\
		ft_rev_str.c \
		ft_strcat.c\
		ft_strchr.c \
		ft_strchr_free.c\
		ft_strcmp.c \
		ft_strdel.c\
		ft_strdup.c \
		ft_strjoin.c\
		ft_strjoin_free.c \
		ft_strlen.c\
		ft_strncmp.c \
		ft_strnew.c\
		ft_strpush.c \
		ft_strsub.c\
		ft_sym_del.c \
		ft_toupper.c\
		ft_utoa.c \
		str_forward.c \
		ft_printf.c \

OBJ_DIR := objects

INCLUDES := source/ft_printf.h

OBJECTS := $(SRC:.c=.o)
SOURCES := $(addprefix $(SRC_DIR),$(SRC))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: directory $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(INCLUDES) $^ -o $@

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -rf $(NAME)
re:
	@make fclean
	@make all
.PHONY: all clean fclean re
