CC := gcc

FLAGS := -Wall -Werror -Wextra

NAME := libft.a

SRC_DIR := src

OBJ_DIR := obj

INC_DIR := inc

SRCS :=	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_strlen.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strncpy.c\
		ft_isascii.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstpushback.c\
		ft_lstlen.c\
		ft_abs.c\
		ft_choice_sort.c\
		ft_assert.c\
		get_next_line.c\
		ft_max.c\
		ft_min.c

SOURCES := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJECTS := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): directory $(OBJ_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(INC_DIR) $^ -o $@

directory:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re directory
