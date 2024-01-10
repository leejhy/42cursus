CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
INC = push_swap.h
SRCS =	main.c parsing.c parsing_utils.c \
		push.c r_rotate.c rotate.c stack.c swap.c stack_utils.c \
		greedy.c greedy_utils.c greedy_op.c greedy_op_utils.c \
		hard_sort.c find_optimal.c error.c
OBJS = ${SRCS:.c=.o}
BONUS_SRCS =	checker.c checker_utils.c \
				parsing.c parsing_utils.c stack.c error.c \
				push.c r_rotate.c rotate.c swap.c hard_sort.c \
				stack_utils.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
BONUS_INC = checker.h
NAME = push_swap
BONUS_NAME = checker

all : $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS) $(BONUS_INC)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : clean fclean re all bonus