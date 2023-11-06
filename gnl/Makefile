CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
INC = get_next_line.h
NAME = get_next_line

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean
	all

all : $(NAME)

bonus :
	@ADD_BONUS=1 make

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