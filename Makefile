CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR_PART2 = ./part2/
SRCS = $(DIR_PART2)ft_split.c \
		$(DIR_PART2)ft_substr.c \
		$(DIR_PART2)ft_strtrim.c \

OBJS = ${SRCS:.c=.o}
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all
