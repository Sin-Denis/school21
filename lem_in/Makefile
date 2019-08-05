CC := gcc

NAME := lem-in

FLAGS := -Wall -Wextra -Werror

CFILES :=	src/main.c\
			src/vector/src/*.c\
			src/queue/src/*.c\
			src/pair/src/vector_pair/*.c\
			src/pair/src/priority_queue/*.c\
			src/dictionary/src/*.c\
			src/graph/src/vert_vector/*.c\
			src/graph/src/graph/*.c\
			src/graph/src/algorithms/*.c

LIB := 	src/Libftprintf/libftprintf.a

all:
	$(CC) $(FLAGS) -o $(NAME) $(LIB) $(CFILES)

$(NAME): $(LIB) $(CFILES)
	$(CC) $(FLAGS) -o $(NAME) $(LIB) $(CFILES)

leak: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all leak
