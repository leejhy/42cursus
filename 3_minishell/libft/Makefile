.DEFAULT_GOAL := all
SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_printf.c ft_printf_utils1.c ft_printf_utils2.c ft_printf_utils3.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
		ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
DEPS = $(SRCS:.c=.d)
DEPS_BONUS = $(SRCS_BONUS:.c=.d)
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -MMD -MP
-include $(DEPS)

ifdef WITH_BONUS
	OBJECTS := $(OBJS) $(OBJS_BONUS)
else
	OBJECTS := $(OBJS)
endif

all : $(NAME)

re : fclean all

fclean : clean
	@ rm -rf $(NAME)

clean :
	@ rm -rf $(DEPS)
	@ rm -rf $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS) libft.h.gch

$(NAME) : $(OBJECTS)
	@ ar rc $@ $(OBJECTS)

%.o : %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

bonus :
	@ make WITH_BONUS=1 all

.PHONY: all bonus clean fclean re
