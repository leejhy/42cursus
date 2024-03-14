CC = cc
FLAG = -Werror -Wall -Wextra# -g3 -fsanitize=address
FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIB_DIR = 	./libft
MLX_DIR =	./mlx
GNL_DIR = 	./gnl
GNL_SRCS =	$(GNL_DIR)/get_next_line_utils.c \
			$(GNL_DIR)/get_next_line.c
GNL_OBJS =	$(GNL_SRCS:.c=.o)

PARS_DIR =	./parsing
PARS_SRCS =	$(PARS_DIR)/img_make.c \
			$(PARS_DIR)/img_print.c \
			$(PARS_DIR)/infor_make.c \
			$(PARS_DIR)/key_utils.c \
			$(PARS_DIR)/tool_make.c \
			$(PARS_DIR)/map_check.c
PARS_OBJS = $(PARS_SRCS:.c=.o)

EXEC_DIR = ./executing
EXEC_SRCS = 
EXEC_OBJS = $(EXEC_SRCS:.c=.o)

MAIN_SRCS =	main.c \
			finish.c
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
INC = ./cub3d.h
NAME = cub3D
OBJS = $(GNL_OBJS) $(PARS_OBJS) $(MAIN_OBJS)

all :
	@make -C $(MLX_DIR)
	@install_name_tool -id $(MLX_DIR)/libmlx.dylib $(MLX_DIR)/libmlx.dylib
	@make -C $(LIB_DIR)
	@make $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(OBJS) -L$(LIB_DIR) -lft $(FRAMEWORK) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

.PHONY : clean fclean re all

clean :
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean :
	@make clean
	rm -f $(LIB_DIR)/libft.a
	rm -f libmlx.dylib
	rm -f $(NAME)

re :
	@make fclean
	@make all