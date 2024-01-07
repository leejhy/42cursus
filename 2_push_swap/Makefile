CC = clang
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
INC = push_swap.h
SRCS =	main.c parsing.c parsing_utils.c \
		push.c r_rotate.c rotate.c stack.c swap.c stack_utils.c\
		greedy.c greedy_utils.c greedy_op.c greedy_op_utils.c\
		hard_sort.c find_optimal.c error.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all