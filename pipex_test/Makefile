CC = cc#cc로 수정
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror
INC = pipex.h
SRCS = pipex.c pipex_utils.c ft_split.c get_path.c error.c init.c
OBJS = ${SRCS:.c=.o}
NAME = pipex

all : ${NAME}

${NAME} : $(OBJS) $(INC)
	$(CC) $(CFLAGS) -o ${NAME} ${OBJS}

%.o : %.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all