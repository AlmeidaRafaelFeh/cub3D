NAME = cub3D
INC_DIR = includes
OBJ_DIR = obj
SRC_DIR = src
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
TEST_DIR = tests

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
TEST_BIN = $(TEST_DIR)/test_utils_mlx
TEST_SRCS = $(TEST_DIR)/test_utils_mlx.c $(SRC_DIR)/utils_minilibx/utils_mlx.c
NORM_DIRS = $(INC_DIR) $(SRC_DIR)
CC = cc
DEBUG = -g3 -O0
CFLAGS = -Wall -Wextra -Werror $(DEBUG) \
         -I$(INC_DIR) \
         -I$(LIBFT_DIR)/includes \
         -I$(MINILIBX_DIR)
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

test: $(TEST_BIN)
	@./$(TEST_BIN)

norm:
	@command -v norminette >/dev/null 2>&1 || { echo "norminette not installed"; exit 1; }
	@norminette $(NORM_DIRS)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

$(TEST_BIN): $(TEST_SRCS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(TEST_SRCS) -o $(TEST_BIN)
	@echo "✅ Build complete: $(TEST_BIN)"

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
	@make -sC $(LIBFT_DIR) clean >/dev/null 2>&1
	@make -sC $(MINILIBX_DIR) clean >/dev/null 2>&1
	@echo "✅ Clean: $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean >/dev/null 2>&1
	-@make -sC $(MINILIBX_DIR) fclean >/dev/null 2>&1 || true

re: fclean all

.PHONY: all test norm clean fclean re