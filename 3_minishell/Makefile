CC = clang
CFLAGS = -lreadline -fsanitize=address 
SRCS = main.c
# OBJS = ${SRCS:.c=.o}
NAME = minishell

all : $(NAME)


$(NAME) :
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all