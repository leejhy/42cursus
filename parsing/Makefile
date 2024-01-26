CC = clang
CFLAGS = -Wall -Wextra -Werror
INC = fdf.h
SRCS =	fdf.c fdf_utils.c parsing.c file_check.c readmap.c readmap_utils.c \
		error.c rotation.c init.c \
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = fdf

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(OBJS) -lm  -o $(NAME)
# $(CC) $(OBJS) -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all