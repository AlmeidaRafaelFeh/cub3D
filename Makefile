NAME = cub3D
INC_DIR = includes
OBJ_DIR = obj
SRC_DIR = src
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux

CUB = \
		cub3D.c \
		parsing/main.c \
		render/main.c \
		utils_minilibx/utils_mlx.c

SRCS = \
		$(addprefix $(SRC_DIR)/, $(CUB))

LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CC = cc
DEBUG = -g3 -O0
CFLAGS = -Wall -Wextra -Werror $(DEBUG) \
         -I$(INC_DIR) \
         -I$(LIBFT_DIR)/includes \
         -I$(MINILIBX_DIR)
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MINILIBX):
	@make -sC $(MINILIBX_DIR) DEBUG="$(DEBUG)" >/dev/null 2>&1

$(LIBFT):
	@make -sC $(LIBFT_DIR) DEBUG="$(DEBUG)" >/dev/null 2>&1

clean:
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBFT_DIR) clean >/dev/null 2>&1
	@make -sC $(MINILIBX_DIR) clean >/dev/null 2>&1
	@echo "✅ Clean: $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean >/dev/null 2>&1
	-@make -sC $(MINILIBX_DIR) fclean >/dev/null 2>&1 || true

re: fclean all

.PHONY: all clean fclean re