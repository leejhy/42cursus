CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
INC = pipex.h
SRCS = pipex.c pipex_utils.c ft_split.c get_path.c error.c
OBJS = ${SRCS:.c=.o}
BNS_INC = pipex_bonus.h
BNS_SRCS = init_bonus.c pipex_bonus.c pipex_utils.c ft_split.c get_path.c error.c
BNS_OBJS = ${BNS_SRCS:.c=.o}
NAME = pipex

ifdef ADD_BONUS
	OBJS = $(BNS_OBJS)
	INC = $(BNS_INC)
endif

all : $(NAME)

bonus :
	@ADD_BONUS=1 make

$(NAME) : $(OBJS) $(INC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS) $(BNS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all bonus