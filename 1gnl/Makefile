CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INC = get_next_line.h
SRCS =	get_next_line.c get_next_line_utils.c main.c
NAME = get_next_line.a

all : $(NAME)

cc : $(SRCS) $(INC)
	$(CC) -o $(NAME) $(SRCS)

$(NAME) : $(SRCS) $(INC)
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

clean :
	rm -f $(NAME)

re : clean all

.PHONY : clean re all
