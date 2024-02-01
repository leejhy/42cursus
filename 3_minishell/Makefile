CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRCS = here_doc.c here_doc_utils.c
OBJS = ${SRCS:.c=.o}
NAME = a.out

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all