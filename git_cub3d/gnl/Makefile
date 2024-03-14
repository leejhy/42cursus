CC = cc
FLAG = -Wall -Wextra -Werror -c
NAME = gnl.a
SOURCE = ./get_next_line.c \
		./get_next_line_utils.c
INC = ./get_next_line.h
OBJS = $(SOURCE:.c=.o)
all : $(NAME)

%.o : %.c $(INC)
	$(CC) $(FLAG) $< -o $@ -include $(INC)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

.PHONY : clean fclean re all
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
