CC = clang
CFLAGS = -Wall -Werror -Wextra
INC = push_swap.h
SRCS =	main.c parsing.c push.c r_rotate.c rotate.c \
		stack.c stack_utils.c swap.c hard_sort.c \
		hard_sort_utils.c greedy.c greedy_utils.c greedy_op.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(INC)
	@$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all