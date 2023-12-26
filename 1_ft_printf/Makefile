CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h
SRCS = ft_printf.c ft_printf_utils.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

all : ${NAME}

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all