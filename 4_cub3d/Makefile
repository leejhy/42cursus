CC = cc
FLAG = -Wall -Wextra -Werror
FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIB_DIR = 	./libft
MLX_DIR =	./mlx
GNL_DIR = 	./gnl
GNL_SRCS =	$(GNL_DIR)/get_next_line_utils.c \
			$(GNL_DIR)/get_next_line.c
GNL_OBJS =	$(GNL_SRCS:.c=.o)

PARS_DIR =	./parsing
PARS_SRCS =	$(PARS_DIR)/img_make.c \
			$(PARS_DIR)/wall_make.c \
			$(PARS_DIR)/info_make.c \
			$(PARS_DIR)/map_check.c
PARS_OBJS = $(PARS_SRCS:.c=.o)

EXEC_DIR = ./executing
EXEC_SRCS =	$(EXEC_DIR)/hook.c \
			$(EXEC_DIR)/control_move.c \
			$(EXEC_DIR)/set_vectors.c \
			$(EXEC_DIR)/raycasting.c \
			$(EXEC_DIR)/raycasting_utils.c \
			$(EXEC_DIR)/write_pixel.c

EXEC_OBJS = $(EXEC_SRCS:.c=.o)

MAIN_SRCS =	main.c \
			finish.c
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
INC = ./cub3d.h
NAME = cub3D
OBJS = $(GNL_OBJS) $(PARS_OBJS) $(MAIN_OBJS) $(EXEC_OBJS) $(LIB_DIR)/libft.a

all :
	@make -C $(MLX_DIR)
	@install_name_tool -id $(MLX_DIR)/libmlx.dylib $(MLX_DIR)/libmlx.dylib
	@make -C $(LIB_DIR)
	@make $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(OBJS) $(FLAG) -L$(LIB_DIR) -lft $(FRAMEWORK) -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(FLAG) -Imlx -c $< -o $@

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