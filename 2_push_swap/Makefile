CC = cc
CFLAGE = -Wall -Wextra -Werror
INC = 
SRCS = 
OBJS = ${SRCS:.c=.o}
NAME =

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all bonus