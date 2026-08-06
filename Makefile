NAME = cub3D
INC_DIR = includes
OBJ_DIR = obj
SRC_DIR = src
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux

CUB = \
		cub3D.c \
		parsing/main.c \
		parsing/parsing_utils.c \
		parsing/parsing_map.c \
		parsing/parsing_map_utils.c \
		parsing/parsing_player.c \
		parsing/parsing_scene_utils.c \
		parsing/parsing_scene_header.c \
		parsing/parsing_scene_rows.c \
		parsing/parsing_scene_reader.c \
		parsing/parsing_scene_cleanup.c \
		player/init_player.c \
		player/movement.c \
		raycasting/raycasting.c \
		render/render_main.c \
		render/render_minimap.c \
		render/render_frame.c \
		render/render_background.c \
		render/render_walls.c \
		hooks/hooks.c \
		utils_minilibx/utils_mlx.c

SRCS = \
		$(addprefix $(SRC_DIR)/, $(CUB))

LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NORM_DIRS = $(INC_DIR) $(SRC_DIR)
CC = cc
DEBUG = -g3 -O0
CFLAGS = -Wall -Wextra -Werror $(DEBUG) \
         -I$(INC_DIR) \
         -I$(LIBFT_DIR)/includes \
         -I$(MINILIBX_DIR)
MLX_FLAGS = -L$(MINILIBX_DIR) \
			-lmlx \
			-lXext \
			-lX11 \
			-lm \
			-lz \
			-lbsd

all: $(NAME)

norm:
	@command -v norminette >/dev/null 2>&1 || { echo "norminette not installed"; exit 1; }
	@norminette $(NORM_DIRS)

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
	@rm -f $(TEST_BIN)
	-@make -sC $(LIBFT_DIR) clean >/dev/null 2>&1 || true
	-@make -sC $(MINILIBX_DIR) clean >/dev/null 2>&1 || true
	@echo "✅ Clean: $(NAME)"

clean-tests:
	@rm -rf $(TEST_BIN)
	@rm -rf $(TEST_PARSING_BIN)

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean >/dev/null 2>&1
	-@make -sC $(MINILIBX_DIR) fclean >/dev/null 2>&1 || true

re: fclean all

.PHONY: all test norm clean fclean re
