CC = cc
CFLAGS = -Wall -Werror -Wextra#-g3 -fsanitize=thread
INC = philo.h
SRCS =	main.c \
		parsing.c \
		set_vars.c \
		run_thread.c \
		run_philo.c \
		run_philo_utils.c \
		actions.c
OBJS = ${SRCS:.c=.o}
NAME = philo

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all