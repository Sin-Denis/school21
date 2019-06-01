SRCS=./srcs/*.c
INCLUDES=./includes
LIB=libft.a

all:
	@gcc -c $(SRCS) -I $(INCLUDES)
	@ar crs $(LIB) ./*.o

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(LIB)

re: fclean all