# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nparker <nparker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 13:38:22 by nparker           #+#    #+#              #
#    Updated: 2019/02/05 14:36:27 by nparker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WAC=\033[33m
OKC=\033[32m

NAME	= fillit
SRC		= $(wildcard *.c) 
OBJ		= $(SRC:.c=.o)
INCLUDE = ./libft/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	@make -C $(INCLUDE)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -L$(INCLUDE) -lft
	@echo "$(OKC)FILLIT:\t\tГотов к работе$(NOC)"

clean:
	@rm -rf $(OBJ)
	@make -C $(INCLUDE) clean
	@echo "$(WAC)FILLIT:\t\tОбъектные файлы уничтожены\n\t\tКак твои надежды и мечты$(NOC)"

fclean: clean
	@make -C $(INCLUDE) fclean
	@rm -rf $(NAME)
re: fclean all