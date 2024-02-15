CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g3 -fsanitize=thread
INC = philo.h
SRCS =	main.c \
		parsing.c \
		set_vars.c \
		make_thread.c
# BONUS_SRCS =	
OBJS = ${SRCS:.c=.o}
# BONUS_OBJS = ${BONUS_SRCS:.c=.o}
# BONUS_INC = 
NAME = philo
# BONUS_NAME = philo_bonus

all : $(NAME)

# bonus : $(BONUS_NAME)

# $(BONUS_NAME) : $(BONUS_OBJS) $(BONUS_INC)
# 	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)
# rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)
# rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : clean fclean re all
# .PHONY : clean fclean re all bonus