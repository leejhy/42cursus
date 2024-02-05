.DEFAULT_GOAL := all
# SRCS_MAIN = main.c
SRCS_MAIN = exe_main.c

SRCS_PARS = \
		tokenize.c \
		expansion.c \
		utils.c \
		re_tokenize.c \
		check_valid_syntax.c \
		error_manager.c \
		remove_oper.c \
		parsing.c \
		find_ambigous.c

SRCS_EXEC = execute.c \
			execute_utils.c \
			heredoc.c \
			redirect.c \
			execve_cmd.c

# SRCS_BUILTIN = \
# 		builtin_cd.c \
# 		builtin_echo.c \
# 		builtin_env.c \
# 		builtin_exit.c \
# 		builtin_export.c \
# 		builtin_pwd.c \
# 		builtin_unset.c \
# 		builtin_utils.c

SRCS_BONUS_MAIN = $(SRCS_MAIN:.c=_bonus.c)
SRCS_BONUS_PARS = $(SRCS_PARS:.c=_bonus.c)
SRCS_BONUS_EXEC = $(SRCS_EXEC:.c=_bonus.c)
# SRCS_BONUS_BUILTIN = $(SRCS_BUILTIN:.c=_bonus.c)

OBJS_MAIN = $(SRCS_MAIN:.c=.o)
OBJS_PARS = $(addprefix ./parsing/, $(SRCS_PARS:.c=.o))
OBJS_EXEC = $(addprefix ./executing/, $(SRCS_EXEC:.c=.o))
# OBJS_BUILTIN = $(addprefix ./builtin/, $(SRCS_BUILTIN:.c=.o))
OBJS = $(OBJS_MAIN) $(OBJS_PARS) $(OBJS_EXEC) $(OBJS_BUILTIN)

OBJS_BONUS_MAIN = $(SRCS_BONUS_MAIN:.c=.o)
OBJS_BONUS_PARS = $(addprefix ./parsing_bonus/, $(SRCS_BONUS_PARS:.c=.o))
OBJS_BONUS_EXEC = $(addprefix ./executing_bonus/, $(SRCS_BONUS_EXEC:.c=.o))
OBJS_BONUS_BUILTIN = $(addprefix ./builtin_bonus/, $(SRCS_BONUS_BUILTIN:.c=.o))
OBJS_BONUS = $(OBJS_BONUS_MAIN) $(OBJS_BONUS_PARS) $(OBJS_BONUS_EXEC) $(OBJS_BONUS_BUILTIN)

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
HEADER_DIR = ./header
HEADER_BONUS_DIR = ./header_bonus
READLINE = readline
CC = cc -Wall -Wextra -Werror
NAME = minishell
MANDA = .manda
BONUS = .bonus

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
	@rm -f $(OBJS) $(OBJS_BONUS) $(BONUS) $(MANDA)
	@make -C $(LIBFT_DIR) clean

fclean :
	@echo "minishell : make fclean"
	@rm -f $(OBJS) $(NAME) $(OBJS_BONUS) $(BONUS) $(MANDA)
	@make -C $(LIBFT_DIR) fclean

re : fclean
	@ echo "minishell : make re"
	@make all

.PHONY: all clean fclean re
