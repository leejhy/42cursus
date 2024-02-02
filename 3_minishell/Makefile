.DEFAULT_GOAL := all
SRCS =	main.c \
		tokenize.c \
		expansion.c \
		utils.c \
		re_tokenize.c \
		check_valid_syntax.c \
		error_manager.c \
		remove_oper.c \
		parsing.c \
		here_doc.c
		
SRCS_BONUS = $(SRCS:.c=_bonus.c)
LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
OBJS = $(addprefix ./parsing/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix ./srcs_bonus/, $(SRCS_BONUS:.c=.o))
DEPS = $(addprefix ./parsing/, $(SRCS:.c=.d))
DEPS_BONUS = $(addprefix ./srcs_bonus/, $(SRCS_BONUS:.c=.d))
HEADER_DIR = ./header
HEADER_BONUS_DIR = ./header_bonus
READLINE = readline
CC = cc -Wall -Wextra -Werror -MMD -MP
NAME = minishell
MANDA = .manda
BONUS = .bonus
-include $(DEPS)

all :
	@echo "minishell : make $(NAME)"
	@make $(MANDA)

bonus :
	@echo "minishell : make BONUS"
	@make $(BONUS)

$(LIBFT) :
	@ echo "minishell : make $(LIBFT)"
	@ make -C $(LIBFT_DIR) bonus

$(NAME) : $(LIBFT) $(OBJS)
	@make $(MANDA)

$(MANDA) : $(LIBFT) $(OBJS)
	@rm -rf $(BONUS)
	@touch $(MANDA)
	@$(CC) -o $(NAME) $(OBJS) -l$(READLINE) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -I$(LIBFT_DIR) -I$(HEADER_DIR)

$(BONUS) : $(LIBFT) $(OBJS_BONUS)
	@rm -rf $(MANDA)
	@touch $(BONUS)
	@$(CC) -o $(NAME) $(OBJS_BONUS) -l$(READLINE) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -I$(LIBFT_DIR) -I$(HEADER_BONUS_DIR)

%_bonus.o : %_bonus.c
	@$(CC) -c $< -I$(LIBFT_DIR) -I$(HEADER_BONUS_DIR) -o $@

%.o : %.c
	@$(CC) -c $< -I$(LIBFT_DIR) -I$(HEADER_DIR) -o $@

clean :
	@echo "minishell : make clean"
	@rm -f $(OBJS) $(DEPS) $(OBJS_BONUS) $(BONUS) $(MANDA) $(DEPS_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean :
	@echo "minishell : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS) $(OBJS_BONUS) $(BONUS) $(MANDA) $(DEPS_BONUS)
	@make -C $(LIBFT_DIR) fclean

re : fclean
	@ echo "minishell : make re"
	@make all

.PHONY: all clean fclean re
